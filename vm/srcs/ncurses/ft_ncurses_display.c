/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:57:11 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/02 21:25:24 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "mars.h"

void	ft_info_processus(t_mars *mars, t_processus *process, t_visu *visu)
{
	unsigned	i;

	i = 0;
	if (!process)
		ft_exit(NULL, "no process");
	wattron(visu->info, COLOR_PAIR(15));
	wprintw(visu->info, "\nprocessus -> ");
	wattroff(visu->info, COLOR_PAIR(15));
	wattron(visu->info, COLOR_PAIR(process->player));
	wprintw(visu->info, "%s\n", process->name);
	wattroff(visu->info, COLOR_PAIR(process->player));

	wattron(visu->info, COLOR_PAIR(15));
	wprintw(visu->info, "Last Cycle Live     -> ");
	wattroff(visu->info, COLOR_PAIR(15));
	wattron(visu->info, COLOR_PAIR(process->player));
	wprintw(visu->info, "%u\n", process->last_cycle_live);
	wattroff(visu->info, COLOR_PAIR(process->player));

	wattron(visu->info, COLOR_PAIR(15));
	wprintw(visu->info, "Nbr of Live   -> ");
	wattroff(visu->info, COLOR_PAIR(15));
	wattron(visu->info, COLOR_PAIR(process->player));
	wprintw(visu->info, "%u\n", process->nbr_of_live);
	wattroff(visu->info, COLOR_PAIR(process->player));
}

void	ft_print_process_pc(t_mars *mars, t_visu *visu)
{
	t_processus *p;

	p = mars->process_lst;

	while (p)
	{
		wattron(visu->arena, COLOR_PAIR(p->player + 6));
		mvwprintw(visu->arena, p->pc / 64, p->pc % 64 * 3, "%2.2X", *mars->memory[p->pc]);
		wattroff(visu->arena, COLOR_PAIR(p->player + 6));
		p = p->next;
	}
}

void	ft_info_ram(t_mars *mars, t_visu *visu)
{
	int i;

	if (!mars)
		return ;
	i = 0;
	while (i < MEM_SIZE)
	{
		if (!mars->memory[i][1])
		{
			wattron(visu->arena, COLOR_PAIR(15));
			mvwprintw(visu->arena, i / 64, i % 64 * 3, "%02.2hhX ", mars->memory[i][0]);
		}
		else if (mars->memory[i][1] == 1)
		{
			wattron(visu->arena, COLOR_PAIR(1));
			mvwprintw(visu->arena, i / 64, i % 64 * 3, "%02.2hhX ", mars->memory[i][0]);
		}
		else if (mars->memory[i][1] == 2)
		{
			wattron(visu->arena, COLOR_PAIR(2));
			mvwprintw(visu->arena, i / 64, i % 64 * 3, "%2.2hhX ", mars->memory[i][0]);
		}
		i++;
	}
	ft_print_process_pc(mars, visu);
}

void	ft_info_mars(t_mars *mars, t_visu *visu)
{
	int			i;
	t_processus *p;

	i = -1;
	werase(visu->info);
	attron(COLOR_PAIR(12));
	wprintw(visu->info, "-- MARS --\n\n");
	wprintw(visu->info, "current cycle : %d --- \n\n", mars->current_cycle);
	wprintw(visu->info, "cycle delta : %d --- \n\n", mars->cycle_delta);
	wprintw(visu->info, "next cycle to die : %d --- \n\n", mars->cycle_to_die);
	wprintw(visu->info, "cycle to die : %d --- \n\n", mars->cycle_teta);
	p = mars->process_lst;
	while (++i < (int)mars->count_players)
	{
		ft_info_processus(mars, p, visu);
		p = p->next;
	}
	wrefresh(visu->info);
}

void	ft_debug_info(t_mars *mars, t_visu *visu)
{
	ft_info_mars(mars, visu);
	ft_info_ram(mars, visu);
	wrefresh(visu->arena);
}
