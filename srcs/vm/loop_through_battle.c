/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_through_battle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:46:41 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/18 18:56:48 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (SUCCESS);
}

static int	set_next_instruction(t_mars *mars, t_processus *process)
{
	if (ft_get_opcode(mars, process,
		*mars->memory[ft_global_restriction(process->pc)]) == OPP_ERROR)
		ft_idle_turn(process, mars->current_cycle);
	tab_set_process(mars, process, process->next_instruction_cycle);
	return (SUCCESS);
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
	return (SUCCESS);
}

t_champion	*loop_through_battle(t_mars *mars)
{
	t_visu		*v;
	t_champion	*winner;

	v = &mars->visu;
	while (execute_one_cycle(mars))
	{
		v->current_frame++;
		if (mars->visualisor == NCURSE && v->current_frame == v->frame)
		{
			mars->ft_display(mars, NULL);
			v->current_frame = 0;
		}
		if (v->abort)
		{
			ft_close_ncurses(v);
			ft_exit(mars, "");
		}
		ft_display_dump(mars);
		if ((winner = ft_cycles_handler(mars)) != NULL)
			return (winner);
	}
	return (NULL);
}
