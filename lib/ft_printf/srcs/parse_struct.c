/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:58:44 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/30 17:21:39 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_width(const char *format, t_arg *argument)
{
	int i;

	i = 0;
	if ((i = ft_atoi(format)) || *format == '0')
	{
		argument->width = i;
		if (i == 0)
			return (0);
		return (ft_log_discret(argument->width, 10) + 1);
	}
	else
	{
		argument->width = 0;
		return (0);
	}
}

static int	get_length_modifier(const char *format, t_arg *argument)
{
	int i;

	i = 0;
	if (!*format)
		return (0);
	while (*format == 'h' || *format == 'l' || *format == 'L' || *format == 'q'
			|| *format == 'j' || *format == 'z' || *format == 't')
	{
		if (*format == 'j')
			argument->l_modifier |= PTF_LEN_J(~0);
		else if (*format == 'h' && format[1] == 'h')
			argument->l_modifier |= PTF_LEN_HH(~0);
		else if (*format == 'h' && format[1] != 'h')
			argument->l_modifier |= PTF_LEN_H(~0);
		else if (*format == 'l' && *format + 1 != 'l')
			argument->l_modifier |= PTF_LEN_L(~0);
		else if (*format == 'l' && *format + 1 == 'l')
			argument->l_modifier |= PTF_LEN_LL(~0);
		else if (*format == 'z')
			argument->l_modifier |= PTF_LEN_Z(~0);
		i++;
		format++;
	}
	return (i);
}

static int	get_precision(const char *format, t_arg *argument)
{
	int i;

	i = 0;
	if (!*format)
		return (0);
	if (*format != '.')
	{
		argument->l_modifier |= PTF_NO_PRE(~0);
		argument->precision = 1;
		return (0);
	}
	format++;
	argument->precision = ft_atoi(format);
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	return (i + 1);
}

static int	get_modifier(const char *format, t_arg *argument)
{
	if (!*format)
		return (0);
	if (*format == 's' || *format == 'S' || *format == 'p' ||
			*format == 'i' || *format == 'D' || *format == 'd' ||
			*format == 'o' || *format == 'O' || *format == 'u' ||
			*format == 'c' || *format == 'X' || *format == 'x' ||
			*format == 'C' || *format == '%' || *format == 'U')
	{
		argument->type = *format;
		if (*format == 'D' || *format == 'U' || *format == 'O')
			PTF_TURNON_FLAG(argument->l_modifier, PTF_LEN_LL(PTF_FLAG_ALL));
		if ((*format == 'c' || *format == 's') &&
				PTF_LEN_L(argument->l_modifier))
			argument->type -= ' ';
		if (!PTF_NO_PRE(argument->l_modifier) && PTF_FLAG_ZERO(argument->flags)
				&& *format != '%' && *format != 'c' && *format != 's'
				&& *format != 'S' && *format != 'C')
			PTF_TOGGLE_FLAG(argument->flags, PTF_FLAG_ZERO(argument->flags));
		return (2);
	}
	else
	{
		argument->type = '\0';
		return (0);
	}
}

int			ft_parse_arg(const char *format, t_arg *argument)
{
	int index;

	argument->width = 0;
	argument->flags = 0;
	argument->l_modifier = 0;
	argument->is_negative = 0;
	argument->precision = 1;
	argument->type = 0;
	if (!*format && !format[1])
		return (1);
	format++;
	if (!*format)
		return (1);
	index = 0;
	index += get_flag(format, argument);
	index += get_width(&format[index], argument);
	index += get_precision(&format[index], argument);
	index += get_length_modifier(&format[index], argument);
	index += get_modifier(&format[index], argument);
	return (index);
}
