/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses_print_live.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:43:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/07 00:41:44 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

void	ft_ncurses_print_live(t_mars *mars)
{
	t_visu		*v;
	t_champion	*champ;
	int			i;

	champ = mars->champion_lst;
	v = &mars->visu;
	werase(v->live);
	while (champ)
	{
		i = -1;
		wprintw(v->live, "%s : %-5d ", champ->name, champ->nbr_of_live);
		while (++i < champ->nbr_of_live)
			wprintw(v->live,"%lc", '+');
		wprintw(v->live, "\n");
		champ = champ->next;
	}
}
