/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_mars_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 18:29:38 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/28 20:12:06 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include "libft.h"

void	ft_kill_process(t_mars *mars)
{
	t_processus *process;
	t_processus *tmp;

	process = mars->process_lst;
	while(process)
	{
		if (process->last_cycle_live < mars->cycle_to_die)
		{
			process->name = ft_strdup("killed");
		}
		process = process->next;
	}
}

void	ft_cycles_handler(t_mars *mars)
{
	mars->current_cycle++;
	if (mars->current_cycle == mars->cycle_to_die)
	{
		ft_kill_process(mars);
		mars->cycle_to_die += mars->cycle_teta;
		mars->cycle_teta -= mars->cycle_delta;
	}
}
