/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:53:53 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/04 19:13:24 by abiestro         ###   ########.fr       */
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

t_processus *ft_copy_process(t_processus *process, t_mars *mars, unsigned dest)
{
	t_processus	*copy;
	int			i;

	if (!(copy = (t_processus *)malloc(sizeof(*copy))))
		ft_exit(mars, "malloc error\n");
	copy->pc = dest;
	copy->bytes_to_jump = dest;
	i = 0;
	while (i < REG_NUMBER * REG_SIZE)
	{
		copy->registers[i] = process->registers[i];
		i++;
	}
	copy->player = process->player;
	copy->next_instruction_cycle = process->next_instruction_cycle + 1;
	copy->name = process->name;
	copy->next = process->next;
	copy->nbr_of_live = process->nbr_of_live;
	copy->opcode = 0;
	copy->carry = process->carry;
	copy->last_cycle_live = process->last_cycle_live;
	copy->params[0] = 0;
	copy->params[1] = 0;
	copy->params[2] = 0;
	process->next = copy;
	return(copy);
}

int		ft_fork(t_mars *mars, t_processus *process)
{
	unsigned	dest;

	dest = ft_get_mars_value(mars, process->pc + 1, IND_SIZE);
	ft_copy_process(process, mars, ft_global_restriction((short)(process->pc + dest) % IDX_MOD));
	process->bytes_to_jump = process->pc + IND_SIZE;
	return (SUCCESS);
}

