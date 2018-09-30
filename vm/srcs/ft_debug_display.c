/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:57:11 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/30 19:38:33 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "mars.h"

void	ft_info_processus(t_processus *process)
{
	unsigned	i;

	i = 0;
	if (!process)
		ft_exit(NULL, "no process");
	printf("\nprocessus -> %s\n", process->name);
	printf("pc        -> %d\n", process->pc);
	printf("player    -> %d\n", process->player);
	while (i < REG_NUMBER)
	{
		printf("register %2X = %2X || ", i, ft_get_register(process, i));
		if (!((i + 1) % (REG_NUMBER / 4)))
			printf("\n");
		i++;
	}
	printf("\n");
}

void	ft_info_ram(t_mars *mars)
{
	int i;
	int save;

	if (!mars)
		return ;
	i = 0;
	while (i < MEM_SIZE)
	{
		save = mars->memory[i++];
		save = save & 255;
		if (save)
			printf("\33[0;32m%02.2x ", save);
		else
			printf("\33[0;0m%02.2x ", save);
		if (!(i % 64))
			printf("\n");
	}
}

void	ft_info_mars(t_mars *mars)
{
	printf("-- MARS --\n");
	printf("current cycle : %d --- ", mars->current_cycle);
	printf("cycle delta : %d --- ", mars->cycle_delta);
	printf("next cycle to die : %d --- ", mars->cycle_to_die);
	printf("cycle to die : %d --- \n\n", mars->cycle_teta);
}

void	ft_debug_info(t_mars *mars)
{
	t_processus *tmp;

	system("@cls||clear");
	tmp = mars->process_lst;
	while (tmp)
	{
		ft_info_processus(tmp);
		tmp = tmp->next;
	}
	ft_info_mars(mars);
	ft_info_ram(mars);
}
