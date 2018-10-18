/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opcode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:43:32 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/18 14:22:05 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include "operations.h"

int		ft_get_opcode(t_mars *mars, t_processus *process, t_byte opcode)
{
	if (opcode < 1 || opcode > 16)
		return (OPP_ERROR);
	process->opcode = g_opps[opcode - 1].f;
	process->next_instruction_cycle =
		mars->current_cycle + g_opps[opcode - 1].latence;
	return (SUCCESS);
}

char	*ft_get_opcode_name(t_mars *mars, t_processus *process)
{
	int opcode;

	opcode = *mars->memory[ft_global_restriction(process->pc)];
	if (!opcode || opcode >= 17)
		return (NULL);
	return (g_opps[opcode - 1].name);
}
