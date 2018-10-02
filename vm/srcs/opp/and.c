/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:08:02 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/02 14:22:09 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** And - 0x06
**
** OCP: ✅    Add: ✅      Carry: ✅    Cycle: 6
** @params 1 : REG | ID | Direct4 Int
** @params 2 : REG | ID | Direct4 Int
** @params dest	: REG
**
** Effectue un AND logique entre les deux premiers paramametres
** et stock le resultat dans le troisieme paramametre.
** Si la valeur resultante est egale a zero,
** alors le carry passe a l'etat un, sinon a l'etat zero.
*/

int		and(t_mars *mars, t_processus *process)
{
	printf("BONJOUR AND\n");
	ft_get_params(process, mars, DIRECT4, *mars->memory[process->pc + 1]);
	ft_load_register(process, process->params[2], process->params[0]
		& process->params[1]);
	if (process->registers[process->params[2] * REG_SIZE] == 0)
		return (NO_CARRY);
	return (CARRY);
}
