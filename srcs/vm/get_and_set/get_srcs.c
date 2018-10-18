/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_srcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:05:55 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/18 15:03:51 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

unsigned	ft_get_srcs(t_mars *mars, t_processus *process,
	int code, int dir_size)
{
	int source;

	if (code == REG_CODE)
	{
		source = ft_get_mars_value(mars, process->bytes_to_jump, REG);
		process->opcode = (!ft_is_register(source)) ? 0 : process->opcode;
		source = ft_get_register(process, source);
		process->bytes_to_jump += REG;
	}
	else if (code == DIR_CODE)
	{
		source = ft_get_mars_value(mars, process->bytes_to_jump, dir_size);
		process->bytes_to_jump += dir_size;
	}
	else if (code == IND_CODE)
	{
		source = ft_get_mars_value(mars, process->bytes_to_jump, IND_SIZE);
		source = (ft_op_need_restriction(process->opcode))
			? (short)source % IDX_MOD : (short)source;
		source = ft_get_mars_value(mars, process->pc + (short)source, DIRECT4);
		process->bytes_to_jump += IND_SIZE;
	}
	else
		source = 0;
	return (source);
}

unsigned	ft_get_dest(t_mars *mars, t_processus *process,
	int code, int dir_size)
{
	int dest;

	if (code == REG_CODE)
	{
		dest = ft_get_mars_value(mars, process->bytes_to_jump, REG);
		if (!ft_is_register(dest))
			process->opcode = 0;
		process->bytes_to_jump += REG;
	}
	else if (code == DIR_CODE)
	{
		dest = ft_get_mars_value(mars, process->bytes_to_jump, dir_size);
		process->bytes_to_jump += dir_size;
	}
	else if (code == IND_CODE)
	{
		dest = ft_get_mars_value(mars, process->bytes_to_jump, IND_SIZE);
		process->bytes_to_jump += IND_SIZE;
	}
	else
		dest = 0;
	return (dest);
}
