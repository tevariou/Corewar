/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_direct_load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:59:18 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/04 17:58:17 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Long Direct Load - 0x0
**
** OCP: ✅    Add: ❌    Carry: ✅     Cycle: 10
** @params 1		: INDIRECT | DIRECT4 Int
** @params 2 dest	: REG
**
** Identique a Direct Load mais sans restriction de l'adressage.
*/



static int	check_ocp(int ocp)
{
	int param_type1;
	int param_type2;
	int param_type3;

	param_type1 = ft_get_param_type(ocp, 1);
	param_type2 = ft_get_param_type(ocp, 2);
	param_type3 = ft_get_param_type(ocp, 3);
	if (!param_type1 || !param_type2 || param_type3 || ft_get_param_type(ocp, 4))
		return (0);
//	if(param_type2 == REG_CODE && !param_type3 && param_type1 != REG_CODE)
		return (1);
	return (0);
}

int		long_direct_load(t_mars *mars, t_processus *process)
{
	int srcs;
	int dest;
	int opc;

	opc = ft_get_mars_value(mars, process->pc + 1, 1);
	process->bytes_to_jump = process->pc + 2;
	srcs = ft_get_srcs(mars, process, ft_get_param_type(opc, 1), DIRECT4);
	dest = ft_get_dest(mars, process, ft_get_param_type(opc, 2), DIRECT4);
	if(!process->opcode || !check_ocp(opc))
		ft_load_register(process, dest, srcs);
	if (srcs)
		process->carry = 0;
	else
		process->carry = 1;
	return (SUCCESS);
}
