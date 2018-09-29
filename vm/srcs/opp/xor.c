/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:07:31 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/29 19:17:44 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include <stdio.h>

/*
** Xor - 0x08
**
** OCP: ✅    Add: ✅      Carry: ✅    Cycle: 6
** @params 1 : REG | ID | Direct4 Int
** @params 2 : REG | ID | Direct4 Int
** @params dest	: REG
**
** Effectue un XOR logique entre les deux premiers paramametres 
** et stock le resultat dans le troisieme paramametre. 
** Si la valeur resultante est egale a zero, alors le carry passe a l'etat un, 
** sinon a l'etat zero.
*/

int		xor(t_mars *mars, t_processus *process)
{
	// if (mars->current_cycle == process->last_cycle_live + 6)
	// 	process->next_instruction_cycle = mars->current_cycle + 6;
	// if (mars->current_cycle == process->next_instruction_cycle)
	// {
		printf("\nBonjour XOR\n");
		ft_get_ocp(process, mars->memory[process->pc + 1]);
		ft_get_params(process, mars, 4);
	// }
	// else
	// 	return (PROCESS_WAITING);
	return (SUCCESS);
}
