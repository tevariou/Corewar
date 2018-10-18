/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:28:56 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/28 20:01:54 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	minus_size_wchar(int value)
{
	int ret;

	ret = 0;
	if (value > 0xFFFF)
		ret = 3;
	else if (value > 0x7FF)
		ret = 2;
	else if (value > 255 || (MB_CUR_MAX != 1 && value > 127))
		ret = 1;
	return (ret);
}

static int	check_value(int *value, t_arg *argument)
{
	int tot;
	int precision;

	tot = 0;
	precision = argument->precision;
	while (*value && (PTF_NO_PRE(argument->l_modifier) ||
				precision > minus_size_wchar(*value) + 1))
	{
		if ((*value >= 0xd800 && *value <= 0xdfff) ||
				(*value > 255 && MB_CUR_MAX == 1)
				|| *value < 0 || *value > 0x10FFFF)
			return (-1);
		tot = tot + (minus_size_wchar(*value) + 1);
		precision -= (minus_size_wchar(*value) + 1);
		value++;
	}
	return (tot);
}

static int	add_width(char **buffer, t_arg *argument, int *value)
{
	int total;

	total = check_value(value, argument);
	if (!PTF_NO_PRE(argument->l_modifier) && argument->precision < total)
		argument->width -= (argument->precision - 1);
	else
		argument->width -= total;
	while (argument->width-- > 0)
	{
		if (PTF_FLAG_ZERO(argument->flags))
			write_buffer(buffer, '0');
		else
			write_buffer(buffer, ' ');
	}
	return (0);
}

static int	*add_null(int *str)
{
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = 0;
	return (str);
}

int			ft_conv_wstring(char *buffer, t_arg *argument, int *value)
{
	int		*b;
	int		pre;
	int		null_str[7];

	if (!value)
		value = add_null(null_str);
	if (check_value(value, argument) == -1)
		return (-1);
	b = value;
	pre = argument->precision;
	if (!PTF_FLAG_MINUS(argument->flags))
		add_width(&buffer, argument, b);
	if (PTF_NO_PRE(argument->l_modifier))
		while (*value)
			stock_value(&buffer, *value++);
	else
		while (*value && pre >= (minus_size_wchar(*value) + 1))
		{
			pre -= (minus_size_wchar(*value) + 1);
			stock_value(&buffer, *value++);
		}
	if (PTF_FLAG_MINUS(argument->flags))
		add_width(&buffer, argument, b);
	return (1);
}
