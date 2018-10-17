/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:57:11 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/17 17:27:19 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "mars.h"

void	ft_display_memory(t_mars *mars)
{
	int i;

	if (!mars)
		return ;
	i = 0;
	printf("Current_cycle : %d \n", mars->current_cycle);
	while (i < MEM_SIZE)
	{
		if (i == 0)
			printf("0x0000 : ");
		printf("%02.2hhx ", mars->memory[i][0]);
		i++;
		if (!(i % 64) && i != 4096)
			printf("\n%#.4x : ", i);
	}
	printf("\n\n");
}
