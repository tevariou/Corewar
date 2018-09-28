/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_indirect_load.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:03:22 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/28 20:00:57 by lmazeaud         ###   ########.fr       */
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
	return (SUCCESS);
}
