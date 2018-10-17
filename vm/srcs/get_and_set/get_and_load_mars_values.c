/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_load_mars_values.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:05:55 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/17 17:41:15 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

unsigned	ft_get_mars_value(t_mars *mars, unsigned index, unsigned size)
{
	unsigned	i;
	int			value;

	value = 0;
	i = 0;
	while (i < size)
	{
		value = value * 256 +
			(t_byte)*mars->memory[ft_global_restriction(index + i)];
		i++;
	}
	return (value);
}

unsigned	ft_load_mars_value(t_mars *mars, unsigned index,
	unsigned value, unsigned color)
{
	int			i;
	unsigned	tmp;

	tmp = value;
	i = REG_SIZE;
	while (i > 0)
	{
		*mars->memory[ft_global_restriction(index + i - 1)] =
			(t_byte)value % 256;
		mars->memory[ft_global_restriction(index + i - 1)][1] = color;
		i--;
		value = value / 256;
	}
	return (SUCCESS);
}
