/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:24:32 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/29 21:47:32 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_log_discret(unsigned int nb, int base)
{
	int i;

	i = 0;
	while (nb >= (unsigned)base)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

int			ft_cast_uitoa(uintmax_t value, char *tmp, t_arg *arg, int base)
{
	if (PTF_LEN_J(arg->l_modifier))
		ft_unsigned_itoa((uintmax_t)value, tmp, base, 25);
	else if (PTF_LEN_LL(arg->l_modifier))
		ft_unsigned_itoa((unsigned long long)value, tmp, base, 25);
	else if (PTF_LEN_L(arg->l_modifier))
		ft_unsigned_itoa((unsigned long)value, tmp, base, 25);
	else if (PTF_LEN_Z(arg->l_modifier))
		ft_unsigned_itoa((size_t)value, tmp, base, 25);
	else if (PTF_LEN_H(arg->l_modifier) && !PTF_LEN_HH(arg->l_modifier))
		ft_unsigned_itoa((unsigned short)value, tmp, base, 25);
	else if (PTF_LEN_HH(arg->l_modifier))
		ft_unsigned_itoa((unsigned char)value, tmp, base, 25);
	else
		ft_unsigned_itoa((unsigned int)value, tmp, base, 25);
	return (0);
}

static void	ft_cast_itoa_forest(intmax_t value, char *tmp, t_arg *arg, int base)
{
	if (PTF_LEN_Z(arg->l_modifier) && ((long)value >= 0))
		ft_unsigned_itoa((size_t)value, tmp, base, 20);
	else if (PTF_LEN_Z(arg->l_modifier) && (arg->is_negative = 1))
		ft_unsigned_itoa((size_t)-value, tmp, base, 20);
	else if (PTF_LEN_H(arg->l_modifier) &&
			!PTF_LEN_HH(arg->l_modifier) && (short)value >= 0)
		ft_unsigned_itoa((unsigned short)value, tmp, base, 6);
	else if (PTF_LEN_H(arg->l_modifier) &&
			!PTF_LEN_HH(arg->l_modifier) && (arg->is_negative = 1))
		ft_unsigned_itoa((unsigned short)-value, tmp, base, 6);
	else if (PTF_LEN_HH(arg->l_modifier) && (char)value >= 0)
		ft_unsigned_itoa((unsigned char)value % UCHAR_MAX, tmp, base, 4);
	else if (PTF_LEN_HH(arg->l_modifier) && (arg->is_negative = 1))
		ft_unsigned_itoa((unsigned char)-value, tmp, base, 4);
	else if ((int)value < 0 && (arg->is_negative = 1))
		ft_unsigned_itoa(-(unsigned int)value, tmp, base, 10);
}

int			ft_cast_itoa(intmax_t value, char *tmp, t_arg *arg, int base)
{
	ft_unsigned_itoa((unsigned int)value, tmp, base, 10);
	if (PTF_LEN_J(arg->l_modifier) && (intmax_t)value >= 0)
		ft_unsigned_itoa((uintmax_t)value, tmp, base, 20);
	else if (PTF_LEN_J(arg->l_modifier) && (arg->is_negative = 1))
		ft_unsigned_itoa((uintmax_t)-value, tmp, base, 20);
	else if (PTF_LEN_LL(arg->l_modifier) && (long long)value >= 0)
		ft_unsigned_itoa((unsigned long long)value, tmp, base, 20);
	else if (PTF_LEN_LL(arg->l_modifier) && (arg->is_negative = 1))
		ft_unsigned_itoa(-(unsigned long long)value, tmp, base, 20);
	else if ((PTF_LEN_L(arg->l_modifier)) && (long)value >= 0)
		ft_unsigned_itoa((unsigned long)value, tmp, base, 20);
	else if ((PTF_LEN_L(arg->l_modifier)) && (arg->is_negative = 1))
		ft_unsigned_itoa((unsigned long)-value, tmp, base, 20);
	else
		ft_cast_itoa_forest(value, tmp, arg, base);
	return (0);
}
