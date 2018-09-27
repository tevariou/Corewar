/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_mars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:53:45 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/26 17:29:55 by abiestro         ###   ########.fr       */
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
	t_mars	*mars;

	mars = (t_mars *)malloc(sizeof(t_mars));
	if (!mars)
		return (NULL);
	mars->memory = (byte *)malloc(sizeof(byte) * MEM_SIZE);
	if (!mars->memory)
		return (NULL);
	mars->cycle_to_die = CYCLE_TO_DIE;
	mars->count_players = 0;
	mars->cycle_current = 0;
	mars->process_lst = NULL;
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
	while (i < ac)
	{
		if  (!(current_champion = ft_argv_have_champ(av, &i, ac)))
			ft_exit(mars, "bad av");
		mars->count_players++;
		ft_add_processus_to_mars(mars, current_champion);
	}
	if (mars->count_players < 1 || mars->count_players > MAX_PLAYERS )
		ft_exit(mars, E_PLAYERS_COUNT);
	if (!ft_prepare_mars_memory(mars))
		ft_exit(mars, "yep");
	return (mars);
}
