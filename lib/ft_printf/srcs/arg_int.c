/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:24:07 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/08 23:25:22 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	add_sign(char **buffer, t_arg *argument)
{
	if (argument->is_negative)
	{
		write_buffer(buffer, '-');
		return (1);
	}
	else if (PTF_FLAG_PLUS(argument->flags))
	{
		write_buffer(buffer, '+');
		return (1);
	}
	else if (PTF_FLAG_SPACE(argument->flags))
	{
		write_buffer(buffer, ' ');
		return (1);
	}
	return (0);
}

static int	add_precision(char **buffer, t_arg *argument, char *tmp)
{
	int		len;
	int		p;
	char	*b;

	b = *buffer;
	p = argument->precision;
	len = ft_strlen(tmp);
	if (argument->precision == 0 && *tmp == '0')
		return (0);
	while (p-- > len)
		write_buffer(buffer, '0');
	while (*tmp)
		write_buffer(buffer, *tmp++);
	return (ft_strlen(b));
}

static int	add_width(char **buffer, t_arg *argument, int len, int value)
{
	int		sub;
	int		width;
	int		pre;
	char	*b;

	b = *buffer;
	width = argument->width;
	pre = argument->precision;
	sub = (pre > len) ? pre : len;
	if (value == 0 && argument->precision == 0 && argument->width > 0)
		write_buffer(buffer, ' ');
	if ((argument->is_negative == 1 || PTF_FLAG_PLUS(argument->flags)
				|| PTF_FLAG_SPACE(argument->flags)))
		width--;
	while (--width >= sub)
	{
		if (PTF_FLAG_ZERO(argument->flags) && !PTF_FLAG_MINUS(argument->flags))
			write_buffer(buffer, '0');
		else
			write_buffer(buffer, ' ');
	}
	return (ft_strlen(b));
}

int			ft_conv_integer(char *buffer, t_arg *argument, intmax_t value)
{
	char	tmp[20];
	int		len;
	char	*t;

	t = tmp;
	ft_cast_itoa(value, tmp, argument, 10);
	len = 0;
	if (!PTF_FLAG_MINUS(argument->flags))
	{
		if (!PTF_FLAG_ZERO(argument->flags))
			add_width(&buffer, argument, ft_strlen(tmp), value);
		add_sign(&buffer, argument);
		if (PTF_FLAG_ZERO(argument->flags))
			add_width(&buffer, argument, ft_strlen(tmp), value);
	}
	if (PTF_FLAG_MINUS(argument->flags))
		add_sign(&buffer, argument);
	add_precision(&buffer, argument, tmp);
	if (PTF_FLAG_MINUS(argument->flags))
		add_width(&buffer, argument, ft_strlen(tmp), value);
	return (0);
}
