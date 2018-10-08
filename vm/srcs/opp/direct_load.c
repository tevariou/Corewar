/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:10:28 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/05 19:24:16 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Direct_Load - 0x02
**
** OCP: ✅    Add: ✅      Carry: ✅    Cycle: 5
** @params 1 : ID | DIRECT4
** @params dest	: REG
**
** Transfert direct RAM > Registre. Charge le premier parametre dans
** le registre passé en second parametre. Si la valeur du premier parametre
** est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.
*/

int		direct_load(t_mars *mars, t_processus *process)
{
	int	srcs;
	int dest;
	int opc;

	opc = ft_get_mars_value(mars, process->pc + 1, 1);
	process->bytes_to_jump = process->pc + 2;
	srcs = ft_get_srcs(mars, process, ft_get_param_type(opc, 1), DIRECT4);
	dest = ft_get_dest(mars, process, ft_get_param_type(opc, 2), DIRECT4);
	ft_load_register(process, dest, srcs);
	if (srcs)
		process->carry = 0;
	else
		process->carry = 1;
	return (SUCCESS);
}
