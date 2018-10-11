/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:53:53 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/11 19:45:25 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include <stdlib.h>

/*
** Fork - 0x0C
**
** OCP: ❌   Add: ✅      Carry: ❌   Cycle: 800
** @params dest	: DIRECT2 Address RAM
**
** Genere un nouveau processus a l'adresse passée en parametre par copie 
** du processus appelant. Le nouveau processus garde donc l'etat de tout
** les registres et du carry, seul le PC differe
** ( sauf dans le cas d'un fork %0 ).
*/

t_processus *ft_copy_process(t_processus *process, t_mars *mars, short dest)
{
	t_processus	*copy;
	int			i;
	int			reg;

	if (!(copy = (t_processus *)malloc(sizeof(*copy))))
		ft_exit(mars, "malloc error\n");
	copy->pc = dest;
	copy->bytes_to_jump = dest;
	i = 1;
	while (i <= REG_NUMBER)
	{
		reg = ft_get_register(process, i);
		ft_load_register(copy, i, reg);
		i++;
	}
	copy->id = mars->nb_process;
	copy->player = process->player;
	copy->name = process->name;
	copy->next = process->next;
	copy->nbr_of_live = process->nbr_of_live;
	copy->opcode = 0;
	copy->carry = process->carry;
	copy->last_cycle_live = process->last_cycle_live;
	copy->next = NULL;
	tab_set_process(mars, copy, mars->current_cycle + 1);
	return(copy);
}

int		ft_fork(t_mars *mars, t_processus *process)
{
	unsigned	dest;

	dest = ft_get_mars_value(mars, process->pc + 1, IND_SIZE);
	mars->nb_process++;
	ft_copy_process(process, mars, ft_global_restriction(process->pc + (short)dest % IDX_MOD));
	if (dest)
		process->carry = 0;
	else
		process->carry = 1;
	process->bytes_to_jump = process->pc + IND_SIZE + 1;
	return (SUCCESS);
}

