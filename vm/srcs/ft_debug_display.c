/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:57:11 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/06 22:15:03 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "mars.h"

void	ft_info_processus(t_processus *process)
{
	unsigned	i;
	i = 1;
	if (!process)
		ft_exit(NULL, "no process");
	printf("\nprocessus -> %s\n", process->name);
	printf("pc        -> %d   ", process->pc);
	printf("player    -> %d\n", process->player);
	printf("next_instruction_cycle : %d\n", process->next_instruction_cycle);
	printf("last alive : %d\n", process->last_cycle_live);
	printf("jump address: %d\n", process->bytes_to_jump);
	printf("carry: %d\n", process->carry);
	while (i <= REG_NUMBER)
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
	printf("Current_cycle : %d \n", mars->current_cycle);
	while (i < MEM_SIZE)
	{
		if (i == 0)
			printf("0x0000 : ");
		if (!mars->memory[i][1])
			printf("%02.2hhX ", mars->memory[i][0]);
		else
			printf("\33[9%dm%02.2X\33[39m ", mars->memory[i][1], mars->memory[i][0]);
		i++;
		if (!(i % 64) && i != 4096)
			printf("\n%#.4x : ", i);
	}
	printf("\n\n");
}

void	ft_info_mars(t_mars *mars)
{
	printf("\n-- MARS --\n");
	printf("cycle current: %d --- ", mars->current_cycle);
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
	usleep(80000);
}
