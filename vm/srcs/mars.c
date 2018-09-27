/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:31:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/28 01:01:34 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include "asm.h"
#include <unistd.h>

int		main(int ac, char **av)
{
	t_mars		*mars;
	t_pf_opp	opps[NB_OPPS];

	mars = ft_set_mars(ac, av);
	//ft_dump_mars_memory(mars->memory);
	ft_init_opps(opps);
	opps[7].f(NULL);
}
