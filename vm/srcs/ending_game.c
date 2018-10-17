/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:29:00 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/17 18:54:59 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

t_champion	*end_game(t_mars *mars)
{
	t_champion	*c;
	t_champion	*winner;
	t_visu		*v;

	v = &mars->visu;
	c = mars->champion_lst;
	winner = mars->champion_lst;
	while (c)
	{
		if (c->last_cycle_live > winner->last_cycle_live)
			winner = c;
		c = c->next;
	}
	return (winner);
}
