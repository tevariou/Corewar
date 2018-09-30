/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:57:11 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/01 00:19:22 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "mars.h"

void	ft_info_processus(t_mars *mars, t_processus *process)
{
	unsigned	i;
	i = 0;
	if (!process)
		ft_exit(NULL, "no process");
	printw("\nprocessus -> %s\n", process->name);
	printw("pc        -> %d\n", process->pc);
	printw("player    -> %d\n", process->player);
	// while (i < REG_NUMBER)
	// {
	// 	mvwprintw(mars->right, "register %2X = %2X || ", i, ft_get_register(process, i));
	// 	if (!((i + 1) % (REG_NUMBER / 4)))
	// 		mvwprintw("\n");
	// 	i++;
	// }
	printw("\n");
	refresh();
}

void	ft_info_ram(t_mars *mars)
{
	int i;

	if (!mars)
		return ;
	i = 0;
	erase();
	while (i < MEM_SIZE)
	{
		if (!mars->memory[i][1])
		{
			attron(COLOR_PAIR(12));
			printw("%02.2hhx ", mars->memory[i][0]);
		}
		else if (mars->memory[i][1] == 1)
		{
			attron(COLOR_PAIR(1));
			printw("%02.2hhx ", mars->memory[i][0]);
		}
		else if (mars->memory[i][1] == 2)
		{
			attron(COLOR_PAIR(2));
			printw("%2.2hhx ", mars->memory[i][0]);
		}
		i++;
		if (!(i % 64))
			printw("\n");
	}
	refresh();
}

void	ft_info_mars(t_mars *mars)
{
	printw("-- MARS --\n");
	printw("current cycle : %d --- ", mars->current_cycle);
	printw("cycle delta : %d --- ", mars->cycle_delta);
	printw("next cycle to die : %d --- ", mars->cycle_to_die);
	printw("cycle to die : %d --- \n\n", mars->cycle_teta);
}

void	ft_debug_info(t_mars *mars)
{
	t_processus *tmp;

	tmp = mars->process_lst;
	while (tmp)
	{
		ft_info_processus(mars, tmp);
		tmp = tmp->next;
	}
	ft_info_mars(mars);
	ft_info_ram(mars);
}
