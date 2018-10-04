/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ncurse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 21:33:34 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/04 13:43:15 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "visu.h"

static void		create_windows(int coord[4], char *name,	
	WINDOW **box, WINDOW **content)
{
	size_t len;

	*box = newwin(coord[0], coord[1], coord[2], coord[3]);
	box(*box, 0, 0);
	*content = derwin(*box, coord[0] - 2, coord[1] - 4, 1, 2);
	len = ft_strlen(name);
	wmove(*box, 0, (coord[1] - len) / 2 - 3);
	wprintw(*box, " - %s - ", name);
	wrefresh(*box);
	wrefresh(*content);
}

void	ft_ncurses_color(void)
{
	start_color();
	init_color(11, 250, 250, 250);
	init_pair(0, 11, COLOR_BLACK);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(9, COLOR_BLACK, COLOR_CYAN);
	init_pair(10, COLOR_BLACK, COLOR_RED);
	init_pair(11, COLOR_BLACK, COLOR_GREEN);
	init_pair(12, COLOR_WHITE, COLOR_BLACK);
	init_pair(13, COLOR_BLACK, COLOR_GREEN);
	init_pair(14, COLOR_GREEN, COLOR_BLACK);
}

void		ft_ncurses_create_thread(t_visu *visu)
{
	pthread_create(&visu->th_input, NULL, &ft_ncurses_get_input, visu);
}

void	ft_init_ncurses(t_visu *visu)
{
	initscr();
	noecho();
	curs_set(0);
	refresh();
	curs_set(FALSE);
	ft_ncurses_color();
	ft_ncurses_create_thread(visu);
	visu->sleep = 50000;
	visu->pause = OFF;
	create_windows((int[4]){ARENA_H, ARENA_W, 0, 0}, "Arena",
		&visu->arena_box, &visu->arena);
	create_windows((int[4]){INFO_H, INFO_W, 0, ARENA_W}, "Info",
		&visu->info_box, &visu->info);
	create_windows((int[4]){10, ARENA_W + INFO_W, ARENA_H, 0}, "Live",
		&visu->live_box, &visu->live);
}

void	ft_close_ncurses(t_visu *visu)
{
	delwin(visu->arena);
	delwin(visu->info);
	delwin(visu->arena_box);
	delwin(visu->info_box);
	endwin();
}
