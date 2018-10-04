/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indirect_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:56:13 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/04 17:57:20 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Indirect_Load - 0x0A
**
** OCP: ✅    Add: ✅      Carry: ✅    Cycle: 25
** @params 1 :  REG | ID | DIRECT2 address Ram
** @params 1 :  ID | DIRECT2 address Ram
** @params dest	: REG
**
** Transfert indirect RAM > Registre. Charge la valeur a l'adresse resultante
** de l'addition des deux premiers paramametres, dans le registre passé en
** troisieme parametre. Si cette valeur est nulle, alors le carry passe a
** l'etat un, sinon a l'etat zero.
*/

int		indirect_load(t_mars *mars, t_processus *process)
{
	ft_get_params(process, mars, DIRECT2, *mars->memory[process->pc + 1]);
	ft_load_register(process, process->params[2], process->params[0]
		+ process->params[1]);
	if (!(ft_get_register(process, process->params[2])))
		return (process->carry = 1);
	return (process->carry = 0);
}
