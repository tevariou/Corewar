/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_registers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:05:55 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/03 16:53:44 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

unsigned		ft_get_register(t_processus *process, unsigned index)
{
	unsigned value;
	int i;

	if (index > REG_NUMBER)
		return (0);
	value = 0;
	i = 0;
	while (i < REG_SIZE)
	{
		value = value * 256 +
			(t_byte)process->registers[index * REG_SIZE + i];
		i++;
	}
	return (value);
}

unsigned		ft_load_register(t_processus *process, unsigned index, unsigned value)
{
	int i;

	if (index > REG_NUMBER)
		return (0);
	i = 0;
	index++;
	while (++i <= REG_SIZE)
	{
		process->registers[index * REG_SIZE - i] = value % 256;
		value = value / 256;
	}
	return (1);
}

unsigned		ft_get_mars_value(t_mars *mars, unsigned index, unsigned size)
{
	int			i;
	unsigned	value;

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

unsigned 		ft_load_mars_value(t_mars *mars, unsigned index, unsigned value)
{
	int			i;
	unsigned	tmp;

	tmp = value;
	i = REG_SIZE;
	while (i > 0)
	{
		*mars->memory[ft_global_restriction(index + i - 1)] = (t_byte)value % 256;
		i--;
		value = value / 256;
	}
	return (SUCCESS);
}