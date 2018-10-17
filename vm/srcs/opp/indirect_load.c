/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indirect_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:56:13 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/17 16:44:15 by lmazeaud         ###   ########.fr       */
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
		|| !param_type3
		|| ft_get_param_type(ocp, 4))
		return (0);
	return (1);
}

int			indirect_load(t_mars *mars, t_processus *process)
{
	int srcs1;
	int srcs2;
	int dest;
	int opc;
	int address;

	opc = ft_get_mars_value(mars, process->pc + 1, 1);
	process->bytes_to_jump = process->pc + 2;
	srcs1 = ft_get_srcs(mars, process, ft_get_param_type(opc, 1), DIRECT2);
	srcs2 = ft_get_srcs(mars, process, ft_get_param_type(opc, 2), DIRECT2);
	dest = ft_get_dest(mars, process, ft_get_param_type(opc, 3), DIRECT2);
	if (!check_ocp(opc) || !process->opcode)
		return (0);
	address = ft_get_mars_value(mars, process->pc +
		((short)srcs1 + (short)srcs2) % IDX_MOD, REG_SIZE);
	ft_load_register(process, dest, address);
	process->carry = (address) ? 0 : 1;
	return (SUCCESS);
}
