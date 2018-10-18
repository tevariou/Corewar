/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:00:58 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/18 17:43:00 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Long Fork - 0x0F
**
** OCP: ❌     Add: ❌      Carry: ❌    Cycle: 1000
** @params 1	: DIRECT2 Address RAM
**
** Identique a Fork mais sans restriction de l'adressage.
*/

int		long_fork(t_mars *mars, t_processus *process)
{
	unsigned	dest;

	dest = ft_get_mars_value(mars, process->pc + 1, IND_SIZE);
	mars->nb_process++;
	ft_copy_process(process, mars,
		ft_global_restriction(process->pc + (short)dest));
	process->carry = (dest) ? 0 : 1;
	process->bytes_to_jump = process->pc + IND_SIZE + 1;
	return (SUCCESS);
}
