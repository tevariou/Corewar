/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_mars_memory.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 22:00:46 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/18 15:03:51 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "mars.h"
#include <limits.h>

int	ft_read_multiple_champion(t_mars *mars)
{
	int			fd;
	unsigned	i;
	t_processus	*current_process;

	i = 0;
	current_process = tab_see_process(mars, 0);
	while (current_process && (fd = open(current_process->name, O_RDONLY)))
	{
		if (!current_process->pc)
			current_process->pc = i++ * (MEM_SIZE / mars->count_players);
		current_process->bytes_to_jump = current_process->pc;
		ft_load_register(current_process, 1, current_process->player);
		if (!ft_load_champ_from_file_to_memory(mars, current_process, fd))
			ft_exit(mars, E_CHAMPS_WRITE);
		current_process = current_process->next;
		close(fd);
	}
	if (fd < 0)
		ft_exit(mars, E_CHAMPS_READ);
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
