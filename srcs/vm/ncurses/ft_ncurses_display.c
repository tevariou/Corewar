/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:57:11 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/18 15:03:51 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

void	ft_ncurses_print_champs(t_mars *mars, t_champion *champ)
{
	t_visu		*v;

	v = &mars->visu;
	wattron(v->info, COLOR_PAIR(12));
	wprintw(v->info, "\nChampion : ");
	wattroff(v->info, COLOR_PAIR(12));
	wattron(v->info, COLOR_PAIR(champ->id_color));
	wprintw(v->info, "%s\n", champ->name);
	wattroff(v->info, COLOR_PAIR(champ->id_color));
	wattron(v->info, COLOR_PAIR(12));
	wprintw(v->info, "Nb process : ");
	wattroff(v->info, COLOR_PAIR(0));
	wattron(v->info, COLOR_PAIR(champ->id_color));
	wprintw(v->info, "%u\n", champ->nb_process);
	wattroff(v->info, COLOR_PAIR(champ->id_color));
	wattron(v->info, COLOR_PAIR(12));
	wprintw(v->info, "Last Cycle Live : ");
	wattroff(v->info, COLOR_PAIR(12));
	wattron(v->info, COLOR_PAIR(champ->id_color));
	wprintw(v->info, "%u\n", champ->last_cycle_live);
	wattroff(v->info, COLOR_PAIR(champ->id_color));
}

void	ft_ncurses_print_process_pc(t_mars *mars)
{
	t_processus *p;
	t_visu		*v;
	int			i;

	i = 0;
	v = &mars->visu;
	while (i < PT_SIZE)
	{
		p = tab_see_process(mars, i);
		while (p)
		{
			wattron(v->arena, COLOR_PAIR(p->player + 6));
			mvwprintw(v->arena, (ft_global_restriction(p->pc) / 64),
				((ft_global_restriction(p->pc) % 64) * 3), "%2.2hhX",
				*mars->memory[ft_global_restriction(p->pc)]);
			wattroff(v->arena, COLOR_PAIR(p->player + 6));
			p = p->next;
		}
		i++;
	}
}

void	ft_ncurses_info_ram(t_mars *mars)
{
	int		i;
	t_visu	*v;

	if (!mars)
		return ;
	i = 0;
	v = &mars->visu;
	while (i < MEM_SIZE)
	{
		wattron(v->arena, COLOR_PAIR(mars->memory[i][1]));
		mvwprintw(v->arena, i / 64, i % 64 * 3, "%2.2hhX ",
			mars->memory[i][0]);
		wattroff(v->arena, COLOR_PAIR(mars->memory[i][1]));
		i++;
	}
	ft_ncurses_print_process_pc(mars);
}

void	ft_ncurses_info_mars(t_mars *mars)
{
	int			i;
	t_champion	*champ;
	t_visu		*v;

	i = -1;
	v = &mars->visu;
	werase(v->info);
	attron(COLOR_PAIR(12));
	wprintw(v->info, "-- MARS --\n\n");
	wprintw(v->info, "current cycle : %d --- \n\n", mars->current_cycle);
	wprintw(v->info, "cycle delta : %d --- \n\n", mars->cycle_delta);
	wprintw(v->info, "next cycle to die : %d --- \n\n", mars->cycle_to_die);
	wprintw(v->info, "cycle to die : %d --- \n\n", mars->cycle_teta);
	wprintw(v->info, "nb process %d --- \n\n", mars->nb_process);
	champ = mars->champion_lst;
	while (champ)
	{
		ft_ncurses_print_champs(mars, champ);
		champ = champ->next;
	}
	ft_ncurses_print_controlers(v);
}

void	ft_ncurses_display(t_mars *mars, t_processus *process)
{
	t_visu	*v;

	(void)process;
	v = &mars->visu;
	ft_ncurses_info_mars(mars);
	ft_ncurses_info_ram(mars);
	ft_ncurses_print_live(mars);
	ft_ncurses_handle_pause(mars, v);
	wrefresh(v->info);
	wrefresh(v->live);
	wrefresh(v->arena);
	usleep(v->sleep);
}
