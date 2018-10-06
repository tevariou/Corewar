/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_registers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:05:55 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/06 14:52:49 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

unsigned		ft_get_register(t_processus *process, unsigned index)
{
	unsigned value;
	int i;

	if (!index)
		return (0);
	index--;
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

	if (!index)
		return (0);
	if (index > REG_NUMBER)
		return (0);
	i = 0;
	while (++i <= REG_SIZE)
	{
		process->registers[index * REG_SIZE - i] = value % 256;
		value = value / 256;
	}
	return (1);
}
