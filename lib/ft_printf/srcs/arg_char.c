/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:53:47 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/27 11:50:16 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_conv_char(char *buffer, t_arg *argument, char value)
{
	if (PTF_FLAG_MINUS(argument->flags))
		write_buffer(&buffer, value);
	while (argument->width-- > 1)
	{
		if (PTF_FLAG_ZERO(argument->flags))
			write_buffer(&buffer, '0');
		else
			write_buffer(&buffer, ' ');
	}
	if (!PTF_FLAG_MINUS(argument->flags))
		write_buffer(&buffer, value);
	return (0);
}
