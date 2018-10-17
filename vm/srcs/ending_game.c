/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:29:00 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/17 17:32:32 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

void	end_game(t_mars *mars)
{
	t_champion	*c;
	t_champion	*winner;

	c = mars->champion_lst;
	winner = mars->champion_lst;
	while (c)
	{
		if (c->last_cycle_live > winner->last_cycle_live)
			winner = c;
		c = c->next;
	}
	printf("and the winner is : %s\n", winner->name);
	ft_exit(mars, winner->name);
}
