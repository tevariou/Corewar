/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_registers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:05:55 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/28 21:14:16 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

int		ft_get_register(t_processus *process, unsigned index)
{
	int value;
	int i;

	if (index > REG_NUMBER)
		return (0);
	value = 0;
	i = 0;
	while (i < REG_SIZE)
	{
		value = value * 255 +
			(unsigned char)process->registers[index * REG_SIZE + i];
		i++;
	}
	return (value);
}

int		ft_load_register(t_processus *process, unsigned index, int value)
{
	int i;

	if (index > REG_NUMBER)
		return (0);
	i = 1;
	index++;
	while (i < REG_SIZE && value > 255)
	{
		process->registers[index * REG_SIZE - i] = value % 255;
		value = value / 255;
		i++;
	}
	process->registers[index * REG_SIZE - i] = value;
	return (1);
}
