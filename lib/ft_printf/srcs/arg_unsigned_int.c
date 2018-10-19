/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:24:07 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/08 23:38:42 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	add_sign(char **buffer, t_arg *argument)
{
	if (argument->is_negative)
		write_buffer(buffer, '-');
	return (0);
}

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
	return (1);
}

static int	add_width(char **buffer, t_arg *argument, int len)
{
	int		sub;
	int		width;
	int		pre;

	width = argument->width;
	pre = argument->precision;
	sub = (pre > len) ? pre : len;
	if ((argument->is_negative == 1 || PTF_FLAG_PLUS(argument->flags)
				|| PTF_FLAG_SPACE(argument->flags)))
		width--;
	while (width - 1 >= sub)
	{
		if (PTF_FLAG_ZERO(argument->flags) && !PTF_FLAG_MINUS(argument->flags))
			write_buffer(buffer, '0');
		else
			write_buffer(buffer, ' ');
		width--;
	}
	return (1);
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
			add_width(&buffer, argument, ft_strlen(tmp));
		add_sign(&buffer, argument);
		if (PTF_FLAG_ZERO(argument->flags))
			add_width(&buffer, argument, ft_strlen(tmp));
	}
	if (PTF_FLAG_MINUS(argument->flags))
		add_sign(&buffer, argument);
	add_precision(&buffer, argument, tmp);
	if (PTF_FLAG_MINUS(argument->flags))
		add_width(&buffer, argument, ft_strlen(tmp));
	return (0);
}
