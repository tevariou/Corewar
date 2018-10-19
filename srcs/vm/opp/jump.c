/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:03:06 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/19 14:03:34 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Jump - 0x09
**
** OCP: ❌    Add: ❌      Carry: ❌     Cycle: 20
** @params dest	: DIRECT2 Address RAM
**
** Saute a l'adresse passé en parametre si le carry est a l'etat un.
** L'adresse devient alors celle de la prochaine instruction. Si le carry
** est a l'etat zero, rien ne se passe et le flot continue normalement jusqu'a
** l'instruction suivante. Rien ne precise si l'instruction consomme
** la totalité de ces cycles dans ce cas, a vous d'en decider.
*/

int		jump(t_mars *mars, t_processus *process)
{
	unsigned dest;

	if (!process->carry)
	{
		process->bytes_to_jump = process->pc + IND_SIZE + 1;
		return (process->carry);
	}
	dest = ft_get_mars_value(mars, process->pc + 1, IND_SIZE);
	process->pc = ft_global_restriction(process->pc + ((short)dest) % IDX_MOD);
	process->bytes_to_jump = process->pc;
	return (process->carry);
}
