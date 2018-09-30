/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:10:28 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/30 23:45:34 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Direct_Load - 0x02
**
** OCP: ✅    Add: ✅      Carry: ✅    Cycle: 5
** @params 1 : ID | DIRECT
** @params dest	: REG
**
** Transfert direct RAM > Registre. Charge le premier parametre dans
** le registre passé en second parametre. Si la valeur du premier parametre
** est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.
*/

int		direct_load(t_mars *mars, t_processus *process)
{
	ft_get_params(process, mars, DIRECT4, *mars->memory[process->pc + 1]);
	ft_load_register(process, process->params[0], process->params[1]);
	if (process->params[1])
		return (0);
	return (1);
}
