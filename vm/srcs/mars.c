/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:31:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/04 09:35:39 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	t_mars		*mars;
	t_visu		visu;

	ft_init_ncurses(&visu);
	mars = ft_set_mars(ac, av);
	loop_through_battle(mars, &visu);
	ft_close_ncurses(&visu);
	return (SUCCESS);
}
