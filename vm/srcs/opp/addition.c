/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:46:20 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/04 17:54:33 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Addition - 0x04
**
** OCP: ✅    Add: ❌    Carry: ✅     Cycle: 10
** @params 1		: REG
** @params 2 		: REG
** @params dest		: REG
**
** Ajoute le second parametre au premier parametre, et stock le resultat dans
** le troisieme parametre. Si la valeur resultante est egale a zero,
** alors le carry passe a l'etat un, sinon a l'etat zero.
*/

int		addition(t_mars *mars, t_processus *process)
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
	ft_load_register(process, desti, srcs1 + srcs2);
	if (srcs1 + srcs2)
		process->carry = 0;
	else
		process->carry = 1;
	return (SUCCESS);
}
