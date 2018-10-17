/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:07:31 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/16 16:45:08 by lmazeaud         ###   ########.fr       */
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
	int srcs1;
	int srcs2;
	int desti;
	int opc;

	process->bytes_to_jump = process->pc + 2;
	opc = ft_get_mars_value(mars, process->pc + 1, 1);
	srcs1 = ft_get_srcs(mars, process, ft_get_param_type(opc, 1), DIRECT4);
	srcs2 = ft_get_srcs(mars, process, ft_get_param_type(opc, 2), DIRECT4);
	desti = ft_get_dest(mars, process, ft_get_param_type(opc, 3), DIRECT4);
	ft_load_register(process, desti, srcs1 ^ srcs2);
	process->carry = (srcs1 ^ srcs2) ? 0 : 1;
	return (SUCCESS);
}
