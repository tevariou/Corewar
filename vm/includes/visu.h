/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 13:56:19 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/02 21:22:41 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# define ARENA_H	(LINES - 20)
# define ARENA_W	(COLS - 168)
# define INFO_H		(LINES - 20)
# define INFO_W		68


# include <ncurses.h>

typedef struct		s_visu
{
	WINDOW			*arena_box;
	WINDOW			*info_box;
	WINDOW			*arena;
	WINDOW			*info;
}					t_visu;

/*
** Ncurses
*/
void				ft_init_ncurses(t_visu *visu);
void				ft_close_ncurses(t_visu *visu);

#endif
