/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ncurse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 21:33:34 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/18 18:32:26 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft.h"

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

void			ft_ncurses_color(void)
{
	start_color();
	init_color(11, 800, 800, 800);
	init_color(COLOR_YELLOW, 1000, 500, 0);
	init_pair(0, 11, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_BLACK, COLOR_GREEN);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_BLUE);
	init_pair(10, COLOR_BLACK, COLOR_YELLOW);
	init_pair(12, COLOR_WHITE, COLOR_BLACK);
}

void			ft_ncurses_create_thread(t_visu *visu)
{
	pthread_create(&visu->th_input, NULL, &ft_ncurses_get_input, visu);
}

void			ft_init_ncurses(t_visu *visu)
{
	initscr();
	noecho();
	curs_set(0);
	refresh();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	ft_ncurses_color();
	ft_ncurses_create_thread(visu);
	visu->sleep = 25000;
	visu->speed = 40;
	visu->pause = OFF;
	visu->abort = OFF;
	visu->frame = 1;
	visu->current_frame = 0;
	create_windows((int[4]){ARENA_H, ARENA_W, 0, 0}, "Arena",
		&visu->arena_box, &visu->arena);
	create_windows((int[4]){INFO_H, INFO_W, 0, ARENA_W}, "Info",
		&visu->info_box, &visu->info);
	create_windows((int[4]){7, ARENA_W + INFO_W, ARENA_H, 0}, "Live",
		&visu->live_box, &visu->live);
	ft_ncurses_print_intro(visu);
}

void			ft_close_ncurses(t_visu *visu)
{
	delwin(visu->arena);
	delwin(visu->info);
	delwin(visu->arena_box);
	delwin(visu->info_box);
	endwin();
}
