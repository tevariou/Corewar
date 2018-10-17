/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_mars_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 18:29:38 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/17 17:37:47 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include "libft.h"

int		ft_kill_process(t_mars *mars)
{
	unsigned	i;
	t_processus	*tmp;
	int			at_least_one;

	at_least_one = 0;
	i = mars->current_cycle;
	while (i < mars->current_cycle + PT_SIZE + 1)
	{
		while ((tmp = tab_get_next_process(mars, i)))
		{
			if (tmp->last_cycle_live <= mars->current_cycle - mars->cycle_teta)
			{
				free(tmp);
				mars->nb_process--;
			}
			else
			{
				set_jump_stock(mars, tmp);
				at_least_one = 1;
			}
		}
		while ((tmp = get_jump_stock(mars)))
			tab_set_process(mars, tmp, i);
		i++;
	}
	return (at_least_one);
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
		if (!ft_kill_process(mars))
			 end_game(mars);
		if (mars->nbr_of_live >= NBR_LIVE || mars->max_check == 1)
		{
			mars->max_check = MAX_CHECKS;
			mars->cycle_to_die += mars->cycle_teta;
			mars->cycle_teta -= mars->cycle_delta;
			ft_init_champs_life(mars->champion_lst);
		}
		else
		{
			mars->max_check--;
			mars->cycle_to_die += mars->cycle_teta;
			ft_init_champs_life(mars->champion_lst);
		}
		mars->nbr_of_live = 0;
	}
}
