/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opcode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:43:32 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/28 20:12:13 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include "asm.h"

int		ft_get_opcode(t_mars *mars, t_processus *process, t_byte opcode)
{
	unsigned	i;

	i = -1;
	while (++i < NB_OPPS)
	{
		if (opcode == g_opps[i].value)
		{
			g_opps[i].f(mars, process);
			return (SUCCESS);
		}
	}
	return (OPP_ERROR);
}
