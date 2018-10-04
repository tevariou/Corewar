/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:07:31 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/04 18:00:23 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

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
	ft_get_params(process, mars, DIRECT4, *mars->memory[process->pc + 1]);
	ft_load_register(process, process->params[2], process->params[0]
		^ process->params[1]);
	if (!(ft_get_register(process, process->params[2])))
		return (process->carry = 1);
	return (process->carry = 0);
}
