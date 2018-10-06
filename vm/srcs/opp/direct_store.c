/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:52:07 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/06 10:45:15 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Direct_Store - 0x03
**
** OCP: ✅    Add: ✅      Carry: ✅    Cycle: 5
** @params 1 :  REG
** @params dest	: REG | ID
**
** Transfert direct Registre > RAM / Registre. Charge le contenu
** du registre passé en premier parametre dans le second parametre.
** Si la valeur du premier parametre est egale a zero, alors le carry
** passe a l'etat un, sinon a l'etat zero.
*/

int direct_store(t_mars *mars, t_processus *process)
{
	ft_get_params(process, mars, NO_SIZE, *mars->memory[process->pc + 1]);
	if ((*mars->memory[process->pc + 1] << 4 & 3) == REG_CODE)
		ft_load_register(process, process->params[1], process->params[0]);
	else
		ft_load_mars_value(mars, process->pc + process->params[1] % IDX_MOD, process->params[0], process->player);
	if (!(ft_get_register(process, process->params[0])))
		return (process->carry = 1);
	return (process->carry = 0);
}
