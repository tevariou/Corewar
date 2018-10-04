/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:31:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/04 17:44:10 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	t_mars		*mars;

	mars = ft_set_mars(ac, av);
	ft_init_ncurses(&mars->visu);
	loop_through_battle(mars);
	ft_close_ncurses(&mars->visu);
	return (SUCCESS);
}
