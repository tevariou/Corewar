/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:52:07 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/06 14:08:04 by lterrail         ###   ########.fr       */
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
	int srcs;
	int dest;
	int ocp;
	int dest_type;

	process->bytes_to_jump = process->pc + 2;
	ocp = ft_get_mars_value(mars, process->pc + 1, 1);
	dest_type = ft_get_param_type(ocp, 2);
	srcs = ft_get_srcs(mars, process, ft_get_param_type(ocp, 1), 4);
	dest = ft_get_dest(mars, process, dest_type, 4);
	if (dest_type == REG_CODE)
		ft_load_register(process, dest, srcs);
	else if (dest_type == IND_CODE)
		ft_load_mars_value(mars, dest + process->pc, srcs, process->player);
	return (process->carry);
}
