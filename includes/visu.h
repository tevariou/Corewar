/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 13:56:19 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/18 19:29:26 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <pthread.h>
# include <ncurses.h>

# define ARENA_H	(LINES - 8)
# define ARENA_W	(COLS - 60)
# define INFO_H		(LINES - 8)
# define INFO_W		60

# define ON			1
# define OFF		0
# define NCURSE		1
# define VERBOSE	3

typedef struct		s_visu
{
	WINDOW			*arena_box;
	WINDOW			*info_box;
	WINDOW			*live_box;
	WINDOW			*live;
	WINDOW			*arena;
	WINDOW			*info;
	unsigned		sleep;
	int				abort;
	int				frame;
	int				current_frame;
	int				pause;
	int				speed;
	pthread_t		th_input;
}					t_visu;

/*
** Ncurses
*/
void				ft_init_ncurses(t_visu *visu);
void				ft_close_ncurses(t_visu *visu);
void				*ft_ncurses_get_input(void *data);
void				ft_ncurses_print_controlers(t_visu *v);
void				ft_ncurses_print_intro(t_visu *v);
void				ft_ncurses_print_how_to_control(t_visu *v);

#endif
