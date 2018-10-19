/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:31:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/19 19:24:57 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "mars.h"

int		main(int ac, char **av)
{
	t_mars		*mars;
	t_champion	*winner;

	setlocale(LC_ALL, "");
	mars = ft_set_mars(ac, av);
	if (mars->visualisor == NCURSE)
		ft_init_ncurses(&mars->visu);
	if (!mars->visualisor)
		ft_display_no_verbose_entry(mars);
	winner = loop_through_battle(mars);
	if (mars->visualisor == NCURSE)
		ft_close_ncurses(&mars->visu);
	ft_printf("Player %d(%s) win the game in %d cycle!!\n",
		winner->id, winner->header.prog_name,
		mars->current_cycle);
	ft_printf("He says : \"%s\" \n", winner->header.comment);
	ft_free_mars(mars);
	return (SUCCESS);
}
