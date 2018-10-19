/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_mars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:53:45 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/19 19:32:34 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Create a new Mars. Malloc what have to. Return a mars if succed, NULL else
*/

t_mars		*ft_mars_alloc(void)
{
	int		i;
	t_mars	*mars;

	if (!(mars = (t_mars *)malloc(sizeof(t_mars))))
		return (NULL);
	i = -1;
	if (!(mars->memory = (t_byte **)malloc(sizeof(t_byte*) * MEM_SIZE)))
		return (NULL);
	while (++i < MEM_SIZE)
		if (!(mars->memory[i] = (t_byte *)malloc(sizeof(t_byte) * 2)))
			return (NULL);
	return (mars);
}

t_mars		*ft_new_mars(void)
{
	t_mars	*mars;

	mars = NULL;
	if (!(mars = ft_mars_alloc()))
		ft_exit(NULL, E_MALLOC);
	mars->cycle_to_die = CYCLE_TO_DIE;
	mars->count_players = 0;
	mars->cycle_delta = CYCLE_DELTA;
	mars->cycle_teta = CYCLE_TO_DIE;
	mars->current_cycle = 0;
	mars->nb_process = 0;
	init_tab_of_process(mars);
	mars->tmp_jump = NULL;
	mars->champion_lst = NULL;
	mars->ft_display = NULL;
	mars->visualisor = 0;
	mars->verbose = -1;
	mars->dump = -1;
	mars->max_check = 10;
	mars->nbr_of_live = 0;
	return (mars);
}

void		set_default_player_number(t_mars *mars, t_processus *current)
{
	int			numero;
	t_champion	*tmp;

	if (!current->player)
		numero = 1;
	else
		numero = current->player;
	tmp = mars->champion_lst;
	while (tmp)
	{
		if (numero == tmp->id)
		{
			if (!current->player)
			{
				numero++;
				tmp = mars->champion_lst;
			}
			else
				ft_exit(mars, E_TWICE_NUM);
		}
		else
			tmp = tmp->next;
	}
	current->player = numero;
}

/*
** start of parsing functions. Will check if parameters are viable and
** return an initialized mars if succed or NULL otherwise.
*/

t_mars		*ft_set_mars(int ac, char **av)
{
	t_mars			*mars;
	t_processus		*current_champion;
	int				i;
	int				value;

	i = 1;
	value = 1;
	mars = ft_new_mars();
	if (!mars || ac == 1)
		ft_exit(mars, E_USAGE);
	while (i < ac && mars->count_players < 5)
	{
		if (!(current_champion = ft_argv_have_champ(mars, av, &i, ac)))
			ft_exit(mars, E_USAGE);
		mars->count_players++;
		current_champion->id_color = mars->count_players;
		set_default_player_number(mars, current_champion);
		ft_add_champ_to_mars(mars, mars->champion_lst, current_champion);
		tab_set_process(mars, current_champion, 0);
	}
	if (mars->count_players < 1 || mars->count_players > MAX_PLAYERS)
		ft_exit(mars, E_PLAYERS_COUNT);
	if (!ft_prepare_mars_memory(mars))
		ft_exit(mars, E_USAGE);
	return (mars);
}
