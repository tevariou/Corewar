/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_mars_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 18:29:38 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/07 16:54:00 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include "libft.h"

void	ft_kill_process(t_mars *mars)
{
	t_processus *process;
	t_processus *tmp;

	process = mars->process_lst;
	while (mars->process_lst &&
			mars->process_lst->last_cycle_live < mars->cycle_to_die)
	{
		tmp = mars->process_lst->next;
		free(mars->process_lst);
		mars->process_lst = tmp;
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
//	if (process && process->last_cycle_live < mars->cycle_to_die && !(tmp->next = NULL))
//		free(process);
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
