/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses_print_intro.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 10:18:59 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/18 18:18:57 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

void	ft_ncurses_print_intro(t_visu *v)
{
	mvwprintw(v->arena, 30, (ARENA_W / 2) - 30,
		" ██████╗ ██████╗ ██████╗ ███████╗██╗    ██╗ █████╗ ██████╗ \n");
	mvwprintw(v->arena, 31, (ARENA_W / 2) - 30,
		"██╔════╝██╔═══██╗██╔══██╗██╔════╝██║    ██║██╔══██╗██╔══██╗\n");
	mvwprintw(v->arena, 32, (ARENA_W / 2) - 30,
		"██║     ██║   ██║██████╔╝█████╗  ██║ █╗ ██║███████║██████╔╝\n");
	mvwprintw(v->arena, 33, (ARENA_W / 2) - 30,
		"██║     ██║   ██║██╔══██╗██╔══╝  ██║███╗██║██╔══██║██╔══██╗\n");
	mvwprintw(v->arena, 34, (ARENA_W / 2) - 30,
		"╚██████╗╚██████╔╝██║  ██║███████╗╚███╔███╔╝██║  ██║██║  ██║\n");
	mvwprintw(v->arena, 35, (ARENA_W / 2) - 30,
		" ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝\n");
	mvwprintw(v->arena, 35, (ARENA_W / 2) - 30,
		"Asm by Triou | Vm by Abiestro & Lterrail | Visu by Lmazeaud\n");
	wrefresh(v->arena);
}

void	ft_ncurses_print_how_to_control(t_visu *v)
{
	wattron(v->info, COLOR_PAIR(4));
	wprintw(v->info, "\n\n\n\n	         +---------+\n");
	wprintw(v->info, "	         |    ↑    |\n");
	wprintw(v->info, "	         |   more  |\n");
	wprintw(v->info, "	         |  frame  |\n");
	wprintw(v->info, "	         |         |\n");
	wprintw(v->info, "	+--------+---------+---------+\n");
	wprintw(v->info, "	|        |         |         |\n");
	wprintw(v->info, "	|  less  |  less   |   more  |\n");
	wprintw(v->info, "	|  speed |  frame  |  speed  |\n");
	wprintw(v->info, "	|    ←   |    ↓    |    →    |\n");
	wprintw(v->info, "	+--------+---------+---------+\n\n\n");
	wprintw(v->info, "	+----------------------------+\n");
	wprintw(v->info, "	|  Space : PAUSE    q: Quit  |\n");
	wprintw(v->info, "	+----------------------------+\n");
	wattroff(v->info, COLOR_PAIR(4));
}
