/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:57:11 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/03 17:46:15 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "mars.h"

void	ft_ncurses_print_processus(t_mars *mars, t_processus *process, t_visu *visu)
{
	unsigned	i;

	i = 0;
	if (!process)
		ft_exit(NULL, "no process");
	wattron(visu->info, COLOR_PAIR(0));
	wprintw(visu->info, "\nprocessus -> ");
	wattroff(visu->info, COLOR_PAIR(0));
	wattron(visu->info, COLOR_PAIR(process->player));
	wprintw(visu->info, "%s\n", process->name);
	wattroff(visu->info, COLOR_PAIR(process->player));

	wattron(visu->info, COLOR_PAIR(0));
	wprintw(visu->info, "Last Cycle Live     -> ");
	wattroff(visu->info, COLOR_PAIR(0));
	wattron(visu->info, COLOR_PAIR(process->player));
	wprintw(visu->info, "%u\n", process->last_cycle_live);
	wattroff(visu->info, COLOR_PAIR(process->player));

	wattron(visu->info, COLOR_PAIR(0));
	wprintw(visu->info, "Nbr of Live   -> ");
	wattroff(visu->info, COLOR_PAIR(0));
	wattron(visu->info, COLOR_PAIR(process->player));
	wprintw(visu->info, "%u\n", process->nbr_of_live);
	wattroff(visu->info, COLOR_PAIR(process->player));
}

void	ft_ncurses_print_process_pc(t_mars *mars, t_visu *visu)
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

void	ft_ncurses_info_ram(t_mars *mars, t_visu *visu)
{
	int i;

	if (!mars)
		return ;
	i = 0;
	while (i < MEM_SIZE)
	{
		wattron(visu->arena, COLOR_PAIR(mars->memory[i][1]));
		mvwprintw(visu->arena, i / 64, i % 64 * 3, "%02.2hhX ", mars->memory[i][0]);
		wattroff(visu->arena, COLOR_PAIR(mars->memory[i][1]));
		i++;
	}
	ft_ncurses_print_process_pc(mars, visu);
}

void	ft_ncurses_info_mars(t_mars *mars, t_visu *visu)
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
	wprintw(visu->info, "pause : %d --- \n\n", visu->pause);
	p = mars->process_lst;
	while (++i < (int)mars->count_players)
	{
		ft_ncurses_print_processus(mars, p, visu);
		p = p->next;
	}
	wrefresh(visu->info);
}

void	ft_ncurses_display(t_mars *mars, t_visu *visu)
{
	ft_ncurses_info_mars(mars, visu);
	ft_ncurses_info_ram(mars, visu);
	wrefresh(visu->arena);
}
