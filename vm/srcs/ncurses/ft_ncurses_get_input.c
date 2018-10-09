/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses_get_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 10:10:24 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/09 12:29:23 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "visu.h"
#include "../../includes/mars.h"

void	*ft_ncurses_get_input(void *data)
{
	t_visu	*visu;
	int		input;

	visu = (t_visu*)data;
	while (1)
	{
		if ((input = getch()) != -1)
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
				visu->frame /= 2;
			if (input == KEY_UP && visu->frame < 63)
				visu->frame *= 2;
			if (input == ' ')
				visu->pause = (visu->pause == OFF) ? ON : OFF;
		}
	}
	pthread_exit(0);
}


void	ft_ncurses_handle_pause(t_visu *v)
{
	if (v->pause == OFF)
	{
		wprintw(v->info, "\n\n\nPAUSE ...\n");
		while (1)
		{
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
