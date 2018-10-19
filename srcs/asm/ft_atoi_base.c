/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:23:30 by triou             #+#    #+#             */
/*   Updated: 2018/10/19 14:44:33 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
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
		asm_warning(a, op->orig, tmp, WARNING_REG);
	return (reg);
}

unsigned short	atoi_base_short(char *str, const char *base)
{
	short	ret;
	int		sign;

	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str += 1;
	ret = 0;
	while (ft_strchr(base, ft_toupper(*str)))
	{
		ret *= ft_strlen(base);
		ret += ft_strchr(base, ft_toupper(*str++)) - base;
	}
	ret *= sign;
	reverse_bytes(&ret, sizeof(ret));
	return (ret);
}

unsigned int	atoi_base_int(char *str, const char *base)
{
	int	ret;
	int	sign;

	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str += 1;
	ret = 0;
	while (ft_strchr(base, ft_toupper(*str)))
	{
		ret *= ft_strlen(base);
		ret += ft_strchr(base, ft_toupper(*str++)) - base;
	}
	ret *= sign;
	reverse_bytes(&ret, sizeof(ret));
	return (ret);
}
