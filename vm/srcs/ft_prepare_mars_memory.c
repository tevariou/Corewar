/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_mars_memory.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 22:00:46 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/28 16:41:42 by abiestro         ###   ########.fr       */
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
	current_process= mars->process_lst;
	while (current_process && (fd = open(current_process->name, O_RDONLY)))
	{
		if (!current_process->pc)
			current_process->pc = i++ * (MEM_SIZE / mars->count_players);
		ft_load_register(current_process, 0, current_process->player);
		ft_info_processus(current_process);
		if (!ft_load_champ_from_file_to_memory(mars->memory, fd, current_process->pc))
			ft_exit(mars, "champions are writted one on the other\n");
		current_process = current_process->next;
	}
	return (1);
}

void    ft_quick_display(t_mars *mars)
{
	int i;
	int save;

	if (!mars)
		return ;
	i = 0;
	while (i < MEM_SIZE)
	{
		save = mars->memory[i++];
		save = save & 255;
		if (save)
			printf("\33[0;32m%02.2x ", save);
		else
			printf("\33[0;0m%02.2x ", save);
		if (!(i % 64))
			printf("\n");
	}
}

int ft_prepare_mars_memory(t_mars *mars)
{
	int			i;
	t_processus	*process;

	i = 0;
	process = mars->process_lst;
	while (i < MEM_SIZE)
		mars->memory[i++] = 0;
	if (!ft_read_multiple_champion(mars))
		return (0);
	ft_quick_display(mars);
	return (1);
}
