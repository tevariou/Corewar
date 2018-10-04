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

int		long_direct_load(t_mars *mars, t_processus *process)
{
	ft_get_params(process, mars, DIRECT4, *mars->memory[process->pc + 1]);
	ft_load_register(process, process->params[1], process->params[0]);
	if (!process->params[0])
		return (process->carry = 1);
	return (process->carry = 0);
}
