/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses_get_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 10:10:24 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/18 19:06:39 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

void	ft_ncurses_get_speed(t_visu *visu, int input)
{
	if (input == KEY_LEFT && visu->sleep < 200000)
	{
		visu->sleep *= 2;
		visu->speed /= 2;
	}
	if (input == KEY_RIGHT && visu->sleep > 2500)
	{
		visu->sleep /= 2;
		visu->speed *= 2;
	}
}

void	ft_ncurses_handle_input(t_visu *visu, int input)
{
	ft_ncurses_get_speed(visu, input);
	if (input == 'q')
	{
		visu->abort = 1;
		pthread_exit(0);
	}
	if (input == KEY_DOWN && visu->frame > 1)
	{
		visu->frame /= 2;
		visu->current_frame = 0;
	}
	if (input == KEY_UP && visu->frame < 63)
	{
		visu->frame *= 2;
		visu->current_frame = 0;
	}
	if (input == ' ')
		visu->pause = (visu->pause == OFF) ? ON : OFF;
}

void	*ft_ncurses_get_input(void *data)
{
	t_visu	*visu;
	int		input;

	visu = (t_visu*)data;
	while (1)
		if ((input = getch()) != -1)
			ft_ncurses_handle_input(visu, input);
	pthread_exit(0);
}

void	ft_ncurses_handle_pause(t_mars *mars, t_visu *v)
{
	if (v->pause == OFF)
	{
		wattron(v->info, COLOR_PAIR(2));
		wprintw(v->info, "\nPAUSE ...\n\n");
		wattroff(v->info, COLOR_PAIR(2));
		while (1)
		{
			if (v->abort)
			{
				ft_close_ncurses(v);
				ft_exit(mars, "");
			}
			if (v->pause == ON)
			{
				werase(v->info);
				wattron(v->info, COLOR_PAIR(1));
				wprintw(v->info, "\nRUNNING ...\n\n");
				wattroff(v->info, COLOR_PAIR(1));
				break ;
			}
			usleep(500);
		}
	}
}

void	ft_ncurses_print_controlers(t_visu *v)
{
	if (v->pause)
	{
		wattron(v->info, COLOR_PAIR(1));
		wprintw(v->info, "\nRUNNING ...\n\n");
		wattroff(v->info, COLOR_PAIR(1));
	}
	else
	{
		wattron(v->info, COLOR_PAIR(2));
		wprintw(v->info, "\nPAUSE ...\n\n");
		wattroff(v->info, COLOR_PAIR(2));
	}
}
