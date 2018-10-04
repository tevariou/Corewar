/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_mars_memory.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 22:00:46 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/03 18:21:52 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "mars.h"

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	ft_read_multiple_champion(t_mars *mars)
{
	int			fd;
	unsigned 	i;
	t_processus	*current_process;

	i = 0;
	current_process = mars->process_lst;
	while (current_process && (fd = open(current_process->name, O_RDONLY)))
	{
		if (!current_process->pc)
			current_process->pc = i++ * (MEM_SIZE / mars->count_players);
		current_process->player = 0xffffffff;
		ft_load_register(current_process, 0, current_process->player);
		if (!ft_load_champ_from_file_to_memory(mars, current_process, fd))
			ft_exit(mars, "champions are writted one on the other\n");
		current_process = current_process->next;
	}
	if (fd < 0)
		ft_exit(mars, "could not read a champion");
	return (1);
}

int	ft_prepare_mars_memory(t_mars *mars)
{
	int			i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		mars->memory[i][0] = 0;
		mars->memory[i][1] = 0;
	}
	if (!ft_read_multiple_champion(mars))
		return (0);
	return (1);
}
