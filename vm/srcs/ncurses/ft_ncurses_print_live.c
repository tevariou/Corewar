/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses_print_live.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:43:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/10 16:38:41 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

void	ft_ncurses_print_live(t_mars *mars)
{
	t_visu		*v;
	t_champion	*champ;
	unsigned		i;

	champ = mars->champion_lst;
	v = &mars->visu;
	werase(v->live);
	while (champ)
	{
		i = -1;
		wattron(v->live, COLOR_PAIR(champ->id_color));
		wprintw(v->live, "%s : %-5d ", champ->name, champ->nbr_of_live);
		while (++i < champ->nbr_of_live)
			wprintw(v->live,"%C", L'▓');
		wprintw(v->live, "\n");
		wattroff(v->live, COLOR_PAIR(champ->id_color));
		champ = champ->next;
	}
}
