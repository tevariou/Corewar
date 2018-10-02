/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_through_battle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:46:41 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/02 21:07:24 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "mars.h"
#include "visu.h"


static int	execut_process_turn(t_mars * mars, t_processus *process)
{
	(void)mars;
	(void)process;
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

void		loop_through_battle(t_mars *mars, t_visu *visu)
{
	mars->process_lst->last_cycle_live = 50000;
	while (execute_one_cycle(mars) && mars->current_cycle < 2500)
	{
		ft_debug_info(mars, visu);
		ft_cycles_handler(mars);
	}
}
