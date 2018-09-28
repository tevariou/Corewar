/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:31:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/28 17:24:33 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include "asm.h"
#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	t_mars		*mars;

	mars = ft_set_mars(ac, av);
	//ft_dump_mars_memory(mars->memory);
	ft_get_ocp(0x68);
	g_opps[7].f(NULL);
	printf("xor : %d\n", g_opps[7].value);

}
