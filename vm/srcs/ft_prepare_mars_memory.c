/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_mars_memory.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 22:00:46 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/01 19:10:47 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "mars.h"

#include <stdio.h>
#include <unistd.h>

int	ft_read_multiple_champion(t_mars *mars)
{
	int			fd;
	int			i;
	t_processus	*current_process;

	i = 0;
	current_process = mars->process_lst;
	while (current_process && (fd = open(current_process->name, O_RDONLY)))
	{
		if (!current_process->pc)
			current_process->pc = i++ * (MEM_SIZE / mars->count_players);
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
	t_processus	*process;

	i = -1;
	process = mars->process_lst;
	while (++i < MEM_SIZE)
	{
		mars->memory[i][0] = 0;
		mars->memory[i][1] = 0;
	}
	if (!ft_read_multiple_champion(mars))
		return (0);
	return (1);
}
