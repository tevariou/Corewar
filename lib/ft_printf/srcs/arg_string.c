/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:28:56 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/29 21:32:27 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	add_width(char **buffer, t_arg *argument, char *value)
{
	char *b;

	b = *buffer;
	if (!PTF_FLAG_MINUS(argument->flags))
	{
		if (argument->precision != 1 &&
				argument->precision <= (int)ft_strlen(value))
			argument->width -= argument->precision;
		else
			argument->width -= ft_strlen(value);
	}
	else
		argument->width -= ft_strlen(value);
	while (argument->width-- > 0)
	{
		if (PTF_FLAG_ZERO(argument->flags))
			write_buffer(buffer, '0');
		else
			write_buffer(buffer, ' ');
	}
	return (ft_strlen(b));
}

int			ft_conv_string(char *buffer, t_arg *argument, char *value)
{
	char	*b;
	char	c[8];
	char	*saved;

	ft_strcpy(c, "(null)");
	if (value == NULL)
		value = c;
	b = value;
	saved = buffer;
	if (!PTF_FLAG_MINUS(argument->flags))
		add_width(&buffer, argument, b);
	if (argument->precision == 1)
		while (*value)
			write_buffer(&buffer, *value++);
	else
		while (argument->precision-- > 0 && *value)
			write_buffer(&buffer, *value++);
	if (PTF_FLAG_MINUS(argument->flags))
		add_width(&buffer, argument, saved);
	return (0);
}
