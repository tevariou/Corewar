/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:14:56 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/06 22:53:53 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include <stdio.h>

static int	ft_params_needed(int (*op)(t_mars *mars, t_processus*))
{
	if (op == live || op == jump || op == ft_fork || op == long_fork || op == aff)
		return (1);
	if (op == direct_load || op == direct_store || op == long_direct_load)
		return (2);
	if (op == addition || op == substraction || op == and || op == or || 
		op == xor || op == indirect_load || op == indirect_store || op == long_indirect_load)
		return (3);
	else
		return (0);
}

static int	ft_stock_reg(t_processus *process, t_mars *mars, int i, int address)
{
	if (!i)
		process->params[2 - i] = ft_get_mars_value(mars, address, REG);
	else if (!(i - 1) && (process->opcode == &direct_load || process->opcode == &direct_store || process->opcode == &long_direct_load))
		process->params[2 - i] = ft_get_mars_value(mars, address, REG);
	else
		process->params[2 - i] = ft_get_register(process, ft_get_mars_value(mars, address, REG));
	return (REG);
}

static int	ft_stock_indirect(t_processus *process, t_mars *mars, int i, int address)
{
	if (!i)
		process->params[2 - i] = ft_get_mars_value(mars, address, INDEX);
	else
		process->params[2 - i] = ft_get_mars_value(mars, ft_get_mars_value(mars, address, 1) + process->pc - 1, INDEX);
	return (INDEX);
}

static int	ft_stock_resticted_indirect(t_processus *process, t_mars *mars, int i, int address)
{
	if (!i || (!(i - 1) && process->opcode == &direct_store))
		process->params[2 - i] = ft_get_mars_value(mars, address, IND_SIZE);
	else
		process->params[2 - i] = ft_get_mars_value(mars, (ft_get_mars_value(mars, address, 1) + process->pc - 1), IND_SIZE);
	return (INDEX);
}

int			ft_get_params(t_processus *process, t_mars *mars, size_t direct_size, unsigned ocp)
{
	int i;
	int code;
	int address;
	int good;

	i = 2;
	good = TRUE;
	process->pc = ft_global_restriction(process->pc);
	address = process->pc + 2;
	while (i >= 3 - ft_params_needed(process->opcode))
	{
		code = (ocp >> ((i + 1) * 2) & 3);
		if (code == REG_CODE)
		{
			if (!ft_is_register(*mars->memory[ft_global_restriction(address)]))
				good = FALSE;
			address += ft_stock_reg(process, mars, i, address);
		}
		else if (code == DIR_CODE)
		{
			process->params[2 - i] = ft_get_mars_value(mars, address, direct_size);
			address += direct_size;
		}
		else if (code == IND_CODE)
		{
			if (!ft_op_need_restriction(process->opcode))
				address += ft_stock_indirect(process, mars, i, address);
			else
				address += ft_stock_resticted_indirect(process, mars, i, address);
		}
		i--;
	}
	process->bytes_to_jump = address;
	return (good);
}
