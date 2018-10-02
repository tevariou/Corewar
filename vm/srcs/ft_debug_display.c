/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:57:11 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/01 21:22:12 by abiestro         ###   ########.fr       */
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
	printf("pc        -> %d   ", process->pc);
	printf("player    -> %d\n", process->player);
	printf("next_instruction_cycle : %d\n", process->next_instruction_cycle);
	printf("last alive : %d\n", process->last_cycle_live);
	printf("jump address: %d\n", process->bytes_to_jump);
	while (i < REG_NUMBER)
	{
		printf("register %2X = %2X || ", i, ft_get_register(process, i));
		if (!((i + 1) % (REG_NUMBER / 4)))
			printf("\n");
		i++;
	}
	printf("\n");
	i = -1;
	while (++i < 3)
		printf("|  param [%d] = %u  |", i + 1, process->params[i]);
	printf("\n");
}

void	ft_info_ram(t_mars *mars)
{
	int i;

	if (!mars)
		return ;
	i = 0;
	while (i < MEM_SIZE)
	{
		if (!mars->memory[i][1])
			printf("%02.2hhX ", mars->memory[i][0]);
		else if (mars->memory[i][1] == 1)
			printf("\33[92m%02.2X\33[39m ", mars->memory[i][0]);
		else if (mars->memory[i][1] == 2)
			printf("\33[91m%02.2X\33[39m ", mars->memory[i][0]);
		i++;
		if (!(i % 64))
			printf("\n");
	}
}

void	ft_info_mars(t_mars *mars)
{
	printf("\n-- MARS --\n");
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
