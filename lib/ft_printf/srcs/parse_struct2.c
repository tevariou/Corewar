/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:23:13 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/29 21:41:33 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_flag(const char *format, t_arg *argument)
{
	int i;

	if (!*format)
		return (0);
	i = 0;
	while (*format && (*format == '-' || *format == '+' || *format == ' ' ||
				*format == '#' || *format == '0'))
	{
		if (*format == '-')
			argument->flags |= PTF_FLAG_MINUS(~0);
		else if (*format == '+')
			argument->flags |= PTF_FLAG_PLUS(~0);
		else if (*format == '0')
			argument->flags |= PTF_FLAG_ZERO(~0);
		else if (*format == ' ')
			argument->flags |= PTF_FLAG_SPACE(~0);
		else if (*format == '#')
			argument->flags |= PTF_FLAG_HASHTAG(~0);
		format++;
		i++;
	}
	return (i);
}
