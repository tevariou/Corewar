/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:31:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/29 19:03:10 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	t_mars		*mars;

	mars = ft_set_mars(ac, av);
	loop_through_battle(mars);
	//ft_dump_mars_memory(mars->memory);
	// ft_get_ocp(NULL, 0x68);
}
