/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 13:56:19 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/03 17:44:38 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <pthread.h>

# define ARENA_H	(LINES - 20)
# define ARENA_W	(COLS - 168)
# define INFO_H		(LINES - 20)
# define INFO_W		68

# define ON			1
# define OFF		0


# include <ncurses.h>

typedef struct		s_visu
{
	WINDOW			*arena_box;
	WINDOW			*info_box;
	WINDOW			*arena;
	WINDOW			*info;
	unsigned		sleep;
	int				pause;
	pthread_t		th_input;
}					t_visu;

/*
** Ncurses
*/
void				ft_init_ncurses(t_visu *visu);
void				ft_close_ncurses(t_visu *visu);
void				*ft_ncurses_get_input(void *data);

#endif
