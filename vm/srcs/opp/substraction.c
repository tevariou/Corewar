/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:08:35 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/17 16:44:53 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Substraction - 0x04
**
** OCP: ✅    Add: ❌    Carry: ✅     Cycle: 10
** @params 1		: REG
** @params 2 		: REG
** @params dest		: REG
**
** Soustrait le second parametre au premier parametre,
** et stock le resultat dans le troisieme parametre. Si la valeur resultante
** est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.
*/

int		substraction(t_mars *mars, t_processus *process)
{
	int srcs1;
	int srcs2;
	int desti;
	int opc;

	process->bytes_to_jump = process->pc + 2;
	opc = ft_get_mars_value(mars, process->pc + 1, 1);
	if (opc != 0x54)
		return (0);
	srcs1 = ft_get_srcs(mars, process, ft_get_param_type(opc, 1), DIRECT4);
	srcs2 = ft_get_srcs(mars, process, ft_get_param_type(opc, 2), DIRECT4);
	desti = ft_get_dest(mars, process, ft_get_param_type(opc, 3), DIRECT4);
	if (!ft_is_register(ft_get_mars_value(mars, process->pc + 2, 1))
		|| !ft_is_register(ft_get_mars_value(mars, process->pc + 3, 1))
		|| !ft_is_register(ft_get_mars_value(mars, process->pc + 4, 1)))
		return (0);
	ft_load_register(process, desti, srcs1 - srcs2);
	process->carry = (srcs1 - srcs2) ? 0 : 1;
	return (SUCCESS);
}
