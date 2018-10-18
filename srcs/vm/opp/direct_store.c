/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:52:07 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/18 17:40:54 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Direct_Store - 0x03
**
** OCP: ✅    Add: ✅      Carry: ✅    Cycle: 5
** @params 1 :  REG
** @params dest	: REG | ID
**
** Transfert direct Registre > RAM / Registre. Charge le contenu
** du registre passé en premier parametre dans le second parametre.
** Si la valeur du premier parametre est egale a zero, alors le carry
** passe a l'etat un, sinon a l'etat zero.
*/

static int	check_ocp(int ocp)
{
	int param_type1;
	int param_type2;
	int param_type3;

	param_type1 = ft_get_param_type(ocp, 1);
	param_type2 = ft_get_param_type(ocp, 2);
	param_type3 = ft_get_param_type(ocp, 3);
	if (!param_type1 || !param_type2)
		return (0);
	return (1);
}

int			direct_store(t_mars *mars, t_processus *process)
{
	int srcs;
	int dest;
	int ocp;
	int dest_type;

	process->bytes_to_jump = process->pc + 2;
	ocp = ft_get_mars_value(mars, process->pc + 1, 1);
	dest_type = ft_get_param_type(ocp, 2);
	srcs = ft_get_srcs(mars, process, ft_get_param_type(ocp, 1), 4);
	dest = ft_get_dest(mars, process, dest_type, 4);
	if (!check_ocp(ocp)
		|| !ft_is_register(ft_get_mars_value(mars, process->pc + 2, 1)))
		return (process->carry);
	if (dest_type == REG_CODE && ft_is_register(dest))
		ft_load_register(process, dest, srcs);
	else if (dest_type == IND_CODE)
		ft_load_mars_value(mars,
			process->pc + ((short)dest) % IDX_MOD, srcs, process->id_color);
	return (SUCCESS);
}
