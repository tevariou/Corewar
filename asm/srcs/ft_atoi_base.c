/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:23:30 by triou             #+#    #+#             */
/*   Updated: 2018/10/01 21:08:30 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <limits.h>

unsigned char	atoi_reg(t_asm *a, t_code *op, char *str)
{
	unsigned char	reg;

	str += 1;
	reg = 0;
	while (ft_isdigit(*str))
	{
		reg *= 10;
		reg += *str++ - '0';
		if (reg > REG_NUMBER)
			asm_error(a, op->orig, WRONG_REG_NUMBER); 
	}
	if (!reg)
		asm_error(a, op->orig, WRONG_REG_NUMBER);
	return (reg);
}

unsigned short	atoi_base_short(char *str, char *base)
{
	int				nb;
	size_t			baselen;
	unsigned short	ret;
	int				sign;

	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str += 1;
	baselen = ft_strlen(base);
	nb = 0;
	while (ft_strchr(base, *str))
	{
		nb *= baselen;
		nb += ft_strchr(base, *str++) - base;
		if (nb > SHRT_MAX && sign > 0)
		{
			nb = SHRT_MAX;
			break ;
		}
		else if (nb > (SHRT_MIN * -1) && sign < 0)
		{
			nb = SHRT_MIN * -1;
			break ;
		}
	}
	ret = (unsigned short)(nb * sign);
	return (ret >> (8 * sizeof(unsigned short) / 2) | ret << (8 * sizeof(unsigned short) / 2));
}

unsigned int	atoi_base_int(char *str, char *base)
{
	long			nb;
	size_t			baselen;
	unsigned int	ret;
	int				sign;

	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str += 1;	
	baselen = ft_strlen(base);
	nb = 0;
	while (ft_strchr(base, *str))
	{
		nb *= baselen;
		nb += ft_strchr(base, *str++) - base;
		if (nb > INT_MAX && sign > 0)
		{
			nb = INT_MAX;
			break ;
		}
		else if (nb > (INT_MIN * -1) && sign < 0)
		{
			nb = INT_MIN * -1;
			break ;
		}
	}
	ret = (unsigned int)(nb * sign);
	return (ret >> (8 * sizeof(unsigned int) / 2) | ret << (8 * sizeof(unsigned int) / 2));
}
