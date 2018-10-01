/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_through_battle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:46:41 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/01 17:07:57 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "mars.h"


static int	execut_process_turn(t_mars * mars, t_processus *current_process)
{
	if(mars->current_cycle == current_process->next_instruction_cycle)	
	{
		if (current_process->opcode)
			current_process->opcode(mars, current_process);
		ft_get_opcode(mars, current_process, *mars->memory[current_process->pc]);
	}
	return (1);
}

static int	execute_one_cycle(t_mars *mars)
{
	t_processus	*current_process;

	current_process = mars->process_lst;
	while (current_process)
	{
		execut_process_turn(mars, current_process);
		current_process = current_process->next;
	}
	return (1);
}

void		loop_through_battle(t_mars *mars)
{
	while (execute_one_cycle(mars) && mars->current_cycle < 2500)
	{
		ft_debug_info(mars);
		ft_cycles_handler(mars);
		usleep(70000);
	}
}
