/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indirect_store.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:59:34 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/04 17:57:38 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Indirect_Store - 0x0B
**
** OCP: ✅    Add: ✅      Carry: ✅    Cycle: 25
** @params 1 :  REG
** @params 1 :  REG | ID | DIRECT2 address RAM
** @params dest	: ID | DIRECT2 address RAM
**
** Transfert indirect Registre > RAM. Charge la valeur contenu dans le registre
** passé en premier parametre a l'adresse resultante de l'addition
** des deux derniers paramametres. Si cette valeur est nulle, alors le carry
** passe a l'etat un, sinon a l'etat zero.
*/

int		indirect_store(t_mars *mars, t_processus *process)
{
	int srcs1;
	int srcs2;
	int srcs3;
	int dest;
	int opc;

	opc = ft_get_mars_value(mars, process->pc + 1, 1);
	process->bytes_to_jump = process->pc + 2;

	srcs1 = ft_get_srcs(mars, process, ft_get_param_type(opc, 1), DIRECT2);
	srcs2 = ft_get_srcs(mars, process, ft_get_param_type(opc, 2), DIRECT2);
	srcs3 = ft_get_srcs(mars, process, ft_get_param_type(opc, 3), DIRECT2);
	dest = process->pc + (short)(srcs2 + srcs3);
	ft_load_mars_value(mars, dest, srcs1, process->player);
}
