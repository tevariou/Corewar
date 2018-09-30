/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opcode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:43:32 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/30 20:36:05 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include "asm.h"

int		ft_get_opcode(t_mars *mars, t_processus *process, t_byte opcode)
{
	if (opcode < 0 || opcode > 15)
		return (OPP_ERROR);
	process->opcode = g_opps[opcode - 1].f;
	process->next_instruction_cycle = mars->current_cycle + g_opps[opcode - 1].latence;
	return (SUCCESS);
}
