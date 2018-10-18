/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:57:11 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/18 18:56:07 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

static void		ft_display_memory(t_mars *mars)
{
	int i;

	if (!mars)
		return ;
	i = 0;
	ft_printf("Current_cycle : %d \n", mars->current_cycle);
	while (i < MEM_SIZE)
	{
		if (i == 0)
			ft_printf("0x0000 : ");
		ft_printf("%02.2hhx ", mars->memory[i][0]);
		i++;
		if (!(i % 64) && i != 4096)
			ft_printf("\n%#.4x : ", i);
	}
	ft_printf("\n\n");
}

void			ft_display_dump(t_mars *mars)
{
	if (!mars->visualisor && mars->dump > 0 &&
		mars->current_cycle == (unsigned)mars->dump)
	{
		ft_display_memory(mars);
		ft_exit(mars, "");
	}
}
