/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_direct_load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:59:18 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/17 16:44:24 by lmazeaud         ###   ########.fr       */
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
	if (!param_type1
		|| !param_type2
		|| param_type3
		|| ft_get_param_type(ocp, 4))
		return (0);
	return (1);
}

int			long_direct_load(t_mars *mars, t_processus *process)
{
	int srcs;
	int dest;
	int opc;

	opc = ft_get_mars_value(mars, process->pc + 1, 1);
	process->bytes_to_jump = process->pc + 2;
	srcs = ft_get_srcs(mars, process, ft_get_param_type(opc, 1), DIRECT4);
	dest = ft_get_dest(mars, process, ft_get_param_type(opc, 2), DIRECT4);
	if (!process->opcode || !check_ocp(opc))
		return (process->carry);
	srcs = srcs >> 16;
	ft_load_register(process, dest, (short)srcs);
	process->carry = ((short)srcs) ? 0 : 1;
	return (SUCCESS);
}
