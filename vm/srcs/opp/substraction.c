/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:08:35 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/04 18:00:11 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Substraction - 0x04
**
** OCP: ✅    Add: ❌    Carry: ✅     Cycle: 10
** @params 1		: REG
** @params 2 		: REG
** @params dest		: REG
**
** Soustrait le second parametre au premier parametre,
** et stock le resultat dans le troisieme parametre. Si la valeur resultante
** est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.
*/

int		substraction(t_mars *mars, t_processus *process)
{
	if (!ft_get_params(process, mars, NO_SIZE, *mars->memory[process->pc + 1]))
		return (process->carry);
	ft_load_register(process, process->params[2], process->params[0]
		- process->params[1]);
	if (!(ft_get_register(process, process->params[2])))
		return (process->carry = 1);
	return (process->carry = 0);
}
