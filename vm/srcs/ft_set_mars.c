/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_mars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:53:45 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/07 21:01:18 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mars.h"
#include "const_errors.h"

/*
** Create a new Mars. Malloc what have to. Return a mars if succed, NULL else
*/

t_mars		*ft_new_mars(void)
{
	int		i;
	t_mars	*mars;

	mars = (t_mars *)malloc(sizeof(t_mars));
	if (!mars)
		return (NULL);
	i = -1;
	if (!(mars->memory = (t_byte **)malloc(sizeof(t_byte*) * MEM_SIZE)))
		return (NULL);
	while (++i < MEM_SIZE)
		if (!(mars->memory[i] = (t_byte *)malloc(sizeof(t_byte) * 2)))
			return (NULL);
	mars->cycle_to_die = CYCLE_TO_DIE;
	mars->count_players = 0;
	mars->cycle_delta = CYCLE_DELTA;
	mars->cycle_teta = CYCLE_TO_DIE;
	mars->current_cycle = 0;
	mars->nb_process = 0;
	mars->process_lst = NULL;
	mars->champion_lst = NULL;
	mars->ft_display = NULL;
	mars->visualisor = 0;
	mars->verbose = -1;
	mars->dump = -1;
	return (mars);
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

	i = 1;
	mars = ft_new_mars();
	if (!mars)
		ft_exit(NULL, E_NO_MARS);
	if (ac == 1)
		ft_exit(mars, "bad av");
	while (i < ac && mars->count_players < 5)
	{
		if (!(current_champion = ft_argv_have_champ(mars, av, &i, ac)))
			ft_exit(mars, "bad av");
		mars->count_players++;
		if (!current_champion->player)
			current_champion->player = mars->count_players;
		ft_add_champ_to_mars(mars, mars->champion_lst, current_champion);
		ft_add_processus_to_mars(mars, current_champion);
	}
	if (mars->count_players < 1 || mars->count_players > MAX_PLAYERS)
		ft_exit(mars, E_PLAYERS_COUNT);
	if (!ft_prepare_mars_memory(mars))
		ft_exit(mars, "yep");
	return (mars);
}
