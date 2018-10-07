/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:31:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/07 16:29:05 by lmazeaud         ###   ########.fr       */
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
	loop_through_battle(mars);
	if (mars->visualisor == NCURSE)
		ft_close_ncurses(&mars->visu);
	return (SUCCESS);
}
