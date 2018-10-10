/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_mars_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 18:29:38 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/10 16:51:52 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include "libft.h"

void	ft_kill_process(t_mars *mars)
{
	t_processus *process;
	t_processus *tmp;
// have to do an iteration instead ofceck for zero
	process = mars->process_lst[0];
	while (mars->process_lst[0] &&
			mars->process_lst[0]->last_cycle_live < mars->cycle_to_die)
	{
		tmp = mars->process_lst[0]->next;
		free(mars->process_lst);
		mars->process_lst[0] = tmp;
	}
	while (process && process->next)
	{
		if (process->next->next && process->next->last_cycle_live < mars->cycle_to_die)
		{
			tmp = process->next;
			process->next = process->next->next;
			free(tmp);
		}
		tmp = process;
		process = process->next;
	}
}

void	ft_init_champs_life(t_champion *champion)
{
	t_champion *champ;

	champ = champion;
	while (champ)
	{
		champ->nbr_of_live = 0;	
		champ = champ->next;
	}
}

void	ft_cycles_handler(t_mars *mars)
{
	mars->current_cycle++;
	if (mars->current_cycle == mars->cycle_to_die)
	{
	//	ft_kill_process(mars);
		mars->cycle_to_die += mars->cycle_teta;
		mars->cycle_teta -= mars->cycle_delta;
		ft_init_champs_life(mars->champion_lst);
	}
}
