/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:04:54 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/01 19:52:43 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Or - 0x07
**
** OCP: ✅    Add: ✅      Carry: ✅    Cycle: 6
** @params 1 : REG | ID | Direct4 Int
** @params 2 : REG | ID | Direct4 Int
** @params dest	: REG
**
** Effectue un OR logique entre les deux premiers paramametres et
** stock le resultat dans le troisieme paramametre. Si la valeur
** resultante est egale a zero, alors le carry passe a l'etat un,
** sinon a l'etat zero.
*/

int		or(t_mars *mars, t_processus *process)
{
	printf("BONJOUR OR\n");
	ft_get_params(process, mars, DIRECT4, *mars->memory[process->pc + 1]);
	ft_load_register(process, process->params[2], process->params[0]
		| process->params[1]);
	if (process->registers[process->params[2] * REG_SIZE] == 0)
		return (NO_CARRY);
	return (CARRY);
}
