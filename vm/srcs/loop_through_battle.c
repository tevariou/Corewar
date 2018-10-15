/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_through_battle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:46:41 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/15 17:37:38 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "mars.h"

static void	ft_idle_turn(t_processus *p, int current_cycle)
{
	p->bytes_to_jump = p->pc + 1;
	p->opcode = 0;
	p->next_instruction_cycle = current_cycle + 1;
}

static int	execut_process_turn(t_mars *mars, t_processus *current_process)
{
	t_visu *v;

	v = &mars->visu;
	if (current_process->opcode)
		current_process->opcode(mars, current_process);
	ft_move_pc(mars, current_process);
	set_jump_stock(mars, current_process);
	return (1);
}

static int	set_next_instruction(t_mars *mars, t_processus *process)
{
	if (ft_get_opcode(mars, process,
		*mars->memory[ft_global_restriction(process->pc)]) == OPP_ERROR)
		ft_idle_turn(process, mars->current_cycle);
	tab_set_process(mars, process, process->next_instruction_cycle);
	return (1);
}

static int	execute_one_cycle(t_mars *mars)
{
	t_processus	*current_process;

	while ((current_process = tab_get_next_process(mars, mars->current_cycle)))
		execut_process_turn(mars, current_process);
	while ((current_process = get_jump_stock(mars)))
	{
		set_next_instruction(mars, current_process);
		if (mars->visualisor == VERBOSE)
			mars->ft_display(mars, current_process);
	}
	return (1);
}

void		loop_through_battle(t_mars *mars)
{
	t_visu *v;

	v = &mars->visu;
	while (execute_one_cycle(mars))
	{
		v->current_frame++;
		if (mars->visualisor > 0 &&
			mars->visualisor != VERBOSE && v->current_frame == v->frame)
		{
			mars->ft_display(mars, NULL);
			v->current_frame = 0;
		}
		if (v->abort)
		{
			ft_close_ncurses(v);
			ft_exit(mars, "");
		}
		if (!mars->visualisor && mars->dump > 0)
			if (mars->current_cycle == (unsigned)mars->dump)
			{
				ft_info_ram(mars);
				ft_exit(mars, "");
			}
		ft_cycles_handler(mars);
	}
}
