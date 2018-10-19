/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:24:07 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/08 23:35:53 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	add_precision(char **buffer, t_arg *argument, char *tmp)
{
	int		len;
	int		p;

	p = argument->precision;
	len = ft_strlen(tmp);
	if (argument->precision == 0 && *tmp == '0')
		return (0);
	while (p-- > len)
		write_buffer(buffer, '0');
	while (*tmp)
		write_buffer(buffer, *tmp++);
	return (0);
}

static int	add_width(char **buffer, t_arg *argument, int len, int value)
{
	int		sub;
	int		width;
	int		pre;

	width = argument->width;
	pre = argument->precision;
	sub = (pre > len) ? pre : len;
	if (PTF_FLAG_HASHTAG(argument->flags) && argument->precision >= 1)
		width -= 2;
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
	return (0);
}

static int	add_type(char **buffer)
{
	write_buffer(buffer, '0');
	write_buffer(buffer, 'x');
	return (0);
}

int			ft_conv_pointeur(char *buffer, t_arg *argument, uintmax_t value)
{
	char	tmp[20];
	int		len;

	len = 0;
	ft_unsigned_itoa(value, tmp, 16, 20);
	argument->flags |= PTF_FLAG_HASHTAG(~0);
	if (!PTF_FLAG_MINUS(argument->flags))
	{
		if (!PTF_FLAG_ZERO(argument->flags))
			add_width(&buffer, argument, ft_strlen(tmp), value);
		add_type(&buffer);
		if (PTF_FLAG_ZERO(argument->flags))
			add_width(&buffer, argument, ft_strlen(tmp), value);
	}
	if (PTF_FLAG_MINUS(argument->flags))
		add_type(&buffer);
	add_precision(&buffer, argument, tmp);
	if (PTF_FLAG_MINUS(argument->flags))
		add_width(&buffer, argument, ft_strlen(tmp), value);
	return (0);
}
