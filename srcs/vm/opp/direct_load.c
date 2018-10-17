/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:10:28 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/16 17:00:28 by lmazeaud         ###   ########.fr       */
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

static int	check_ocp(int ocp)
{
	int param_type1;
	int param_type2;
	int param_type3;

	param_type1 = ft_get_param_type(ocp, 1);
	param_type2 = ft_get_param_type(ocp, 2);
	param_type3 = ft_get_param_type(ocp, 3);
	if (!param_type1
		|| !param_type2
		|| ft_get_param_type(ocp, 3)
		|| ft_get_param_type(ocp, 4))
		return (0);
	return (1);
}

int			direct_load(t_mars *mars, t_processus *process)
{
	int	srcs;
	int dest;
	int opc;

	opc = ft_get_mars_value(mars, process->pc + 1, 1);
	process->bytes_to_jump = process->pc + 2;
	srcs = ft_get_srcs(mars, process, ft_get_param_type(opc, 1), DIRECT4);
	dest = ft_get_dest(mars, process, ft_get_param_type(opc, 2), DIRECT4);
	if (!check_ocp(opc) || !process->opcode)
		return (process->carry);
	ft_load_register(process, dest, srcs);
	process->carry = (srcs) ? 0 : 1;
	return (SUCCESS);
}
