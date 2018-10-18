/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_hashtag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 22:36:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/29 21:30:26 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_conv_hashtag(char *buffer, t_arg *argument)
{
	int len;

	len = 0;
	if (PTF_FLAG_MINUS(argument->flags))
		write_buffer(&buffer, '%');
	while (argument->width-- > 1)
	{
		if (PTF_FLAG_ZERO(argument->flags))
			write_buffer(&buffer, '0');
		else
			write_buffer(&buffer, ' ');
	}
	if (!PTF_FLAG_MINUS(argument->flags))
		write_buffer(&buffer, '%');
	return (len + 1 + argument->width);
}
