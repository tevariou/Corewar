/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:24:07 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/29 21:32:55 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	add_sign(char *buffer, t_arg *argument)
{
	if (argument->is_negative)
	{
		write_buffer(&buffer, '-');
		return (1);
	}
	return (0);
}

static int	add_precision(char *buffer, t_arg *argument, char *tmp)
{
	int		len;
	int		p;
	char	*b;

	b = buffer;
	p = argument->precision;
	len = ft_strlen(tmp);
	if (argument->precision == 0 && *tmp == '0')
		return (0);
	while (p-- > len)
		write_buffer(&buffer, '0');
	while (*tmp)
		write_buffer(&buffer, *tmp++);
	return (ft_strlen(b));
}

static int	add_width(char *buffer, t_arg *argument, int len)
{
	int		sub;
	int		width;
	int		pre;
	char	*b;

	b = buffer;
	width = argument->width;
	pre = argument->precision;
	sub = (pre > len) ? pre : len;
	if ((argument->is_negative == 1 || PTF_FLAG_PLUS(argument->flags)
				|| PTF_FLAG_SPACE(argument->flags)))
		width--;
	while (width - 1 >= sub)
	{
		if (PTF_FLAG_ZERO(argument->flags) && !PTF_FLAG_MINUS(argument->flags))
			write_buffer(&buffer, '0');
		else
			write_buffer(&buffer, ' ');
		width--;
	}
	return (ft_strlen(b));
}

int			ft_conv_unsigned_integer(char *buffer, t_arg *argument,
		uintmax_t value)
{
	char	tmp[20];
	int		len;
	char	*t;

	t = tmp;
	len = 0;
	ft_cast_uitoa(value, t, argument, 10);
	if (!PTF_FLAG_MINUS(argument->flags))
	{
		if (!PTF_FLAG_ZERO(argument->flags))
			len += add_width(&buffer[len], argument, ft_strlen(tmp));
		len += add_sign(&buffer[len], argument);
		if (PTF_FLAG_ZERO(argument->flags))
			len += add_width(&buffer[len], argument, ft_strlen(tmp));
	}
	if (PTF_FLAG_MINUS(argument->flags))
		len += add_sign(&buffer[len], argument);
	len += add_precision(&buffer[len], argument, tmp);
	if (PTF_FLAG_MINUS(argument->flags))
		len += add_width(&buffer[len], argument, ft_strlen(tmp));
	return (0);
}
