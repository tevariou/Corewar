/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:31:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/17 18:59:08 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include <unistd.h>
#include <stdio.h>
#include <locale.h>

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
	printf("The winner is %s\n", winner->header.prog_name);
	printf("He says : \"%s\" \n", winner->header.comment);
	ft_free_mars(mars);
	return (SUCCESS);
}
