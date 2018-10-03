/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:46:20 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/03 20:40:54 by lterrail         ###   ########.fr       */
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
	ft_get_params(process, mars, NO_SIZE, *mars->memory[process->pc + 1]);
	ft_load_register(process, process->params[2], process->params[0]
		+ process->params[1]);
	if (!(ft_get_register(process, process->params[2])))
		return (process->carry = 0);
	return (process->carry = 1);
}
