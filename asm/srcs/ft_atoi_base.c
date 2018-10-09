/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:23:30 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 19:04:57 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <limits.h>

unsigned char	atoi_reg(t_asm *a, t_code *op, char *str)
{
	unsigned char	reg;
	char			*tmp;

	tmp = str++;
	reg = 0;
	while (ft_isdigit(*str))
	{
		reg *= 10;
		reg += *str++ - '0';
		if (reg > REG_NUMBER)
			asm_error(a, op->orig, tmp, WRONG_REG_NUMBER);
	}
	if (!reg)
		asm_error(a, op->orig, tmp, WRONG_REG_NUMBER);
	return (reg);
}

unsigned short	atoi_base_short(char *str, char *base)
{
	int				nb;
	unsigned short	ret;
	int				sign;

	sign = (*str == '-') ? -1 : 1;
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	nb = 0;
	while (ft_strchr(base, *str))
	{
		nb *= ft_strlen(base);
		nb += ft_strchr(base, *str++) - base;
		if (nb > SHRT_MAX && sign > 0)
		{
			nb = SHRT_MAX;
			break ;
		}
		else if ((nb * sign) < SHRT_MIN && sign < 0)
		{
			nb = SHRT_MIN * sign;
			break ;
		}
	}
	ret = (unsigned short)(nb * sign);
	reverse_bytes(&ret, sizeof(ret));
	return (ret);
}

unsigned int	atoi_base_int(char *str, char *base)
{
	long			nb;
	unsigned int	ret;
	int				sign;

	sign = (*str == '-') ? -1 : 1;
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	nb = 0;
	while (ft_strchr(base, *str))
	{
		nb *= ft_strlen(base);
		nb += ft_strchr(base, *str++) - base;
		if (nb > INT_MAX && sign > 0)
		{
			nb = INT_MAX;
			break ;
		}
		else if ((nb * sign) < INT_MIN && sign < 0)
		{
			nb = INT_MIN * sign;
			break ;
		}
	}
	ret = (unsigned int)(nb * sign);
	reverse_bytes(&ret, sizeof(ret));
	return (ret);
}
