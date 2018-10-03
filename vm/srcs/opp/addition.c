/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:46:20 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/03 13:55:37 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Addition - 0x04
**
** OCP: ✅    Add: ❌    Carry: ✅     Cycle: 10
** @params 1		: REG
** @params 2 		: REG
** @params dest		: REG
**
** Ajoute le second parametre au premier parametre, et stock le resultat dans
** le troisieme parametre. Si la valeur resultante est egale a zero,
** alors le carry passe a l'etat un, sinon a l'etat zero.
*/

int		addition(t_mars *mars, t_processus *process)
{
	printf("BONJOUR ADD\n");
	ft_get_params(process, mars, NO_SIZE, *mars->memory[process->pc + 1]);
	ft_load_register(process, process->params[2], process->params[0]
		+ process->params[1]);
	if (process->registers[process->params[2] * REG_SIZE] == 0)
		return (NO_CARRY);
	return (CARRY);
}
