/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses_get_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 10:10:24 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/18 15:02:44 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

void	ft_ncurses_handle_input(t_visu *visu, int input)
{
	if (input == KEY_LEFT && visu->sleep < 200000)
		visu->sleep *= 2;
	if (input == KEY_RIGHT && visu->sleep > 2500)
		visu->sleep /= 2;
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
		wprintw(v->info, "\n\n\nPAUSE ...\n");
		while (1)
		{
			if (v->abort)
			{
				ft_close_ncurses(v);
				ft_exit(mars, NULL);
			}
			if (v->pause == ON)
			{
				werase(v->info);
				wprintw(v->info, "\n\n\nRUNNING ...\n");
				break ;
			}
			usleep(500);
		}
	}
}

void	ft_ncurses_print_controlers(t_visu *v)
{
	(v->pause)
		? wprintw(v->info, "\n\n\n RUNNING ...\n")
		: wprintw(v->info, "\n\n\n PAUSE ...\n");
	wprintw(v->info, "\nCycle/sec : %d \n", (v->sleep / 10000));
	wprintw(v->info, "\nCycle/Frame : %d \n", v->frame);
}
