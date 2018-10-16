/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:31:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/16 16:14:49 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include <unistd.h>
#include <stdio.h>
#include <locale.h>

int		main(int ac, char **av)
{
	t_mars		*mars;

	setlocale(LC_ALL, "");
	mars = ft_set_mars(ac, av);
	if (mars->visualisor == NCURSE)
		ft_init_ncurses(&mars->visu);
	if (!mars->visualisor)
		ft_display_no_verbose_entry(mars);
	loop_through_battle(mars);
	if (mars->visualisor == NCURSE)
		ft_close_ncurses(&mars->visu);
	return (SUCCESS);
}
