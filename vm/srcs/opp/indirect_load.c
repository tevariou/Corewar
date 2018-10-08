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
	int srcs1;
	int srcs2;
	int dest;
	int opc;
	int address;

	opc = ft_get_mars_value(mars, process->pc + 1, 1);
	srcs1 = ft_get_srcs(mars, process, ft_get_param_type(opc, 1), DIRECT4);
	srcs2 = ft_get_srcs(mars, process, ft_get_param_type(opc, 2), DIRECT4);
	dest = ft_get_dest(mars, process, ft_get_param_type(opc, 3), DIRECT2);
	address = ft_get_mars_value(mars, process->pc + srcs1 + srcs2, 4);
	ft_load_register(process, dest, address);
	if (srcs1 + srcs2)
		process->carry = 0;
	else
		process->carry = 1;
	return (SUCCESS);
}
