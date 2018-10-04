/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_indirect_load.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:03:22 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/04 17:59:24 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Long Indirect Load - 0x0E
**
** OCP: ✅    Add: ❌    Carry: ✅     Cycle: 50
** @params 1		: REG |INDIRECT | DIRECT2 Address Ram
** @params 2		: INDIRECT | DIRECT2 Address Ram
** @params dest		: REG
**
** Identique a Indirect Load mais sans restriction de l'adressage.
*/

int		long_indirect_load(t_mars *mars, t_processus *process)
{
	ft_get_params(process, mars, DIRECT2, *mars->memory[process->pc + 1]);
	ft_load_register(process, process->params[2], process->params[0]
		+ process->params[1]);
	if (!(ft_get_register(process, process->params[2])))
		return (process->carry = 1);
	return (process->carry = 0);
}
