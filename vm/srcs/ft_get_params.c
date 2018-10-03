/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:14:56 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/02 16:13:45 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include <stdio.h>

static int	ft_stock_reg(
		t_processus *process, t_mars *mars, int i, int address)
{
	if ((!i || (!(i - 1))) &&
				(process->opcode == &long_direct_load || process->opcode == &direct_store || process->opcode == &direct_load))
	{
		process->params[2 - i] = ft_get_mars_value(mars, address, REG);
	}
	else
		process->params[2 - i] = ft_get_register(process, ft_get_mars_value(mars, address, REG));
	return (REG);
}

static int	ft_stock_indirect(
		t_processus *process, t_mars *mars, int i, int address)
{
	if ((!i || (!(i - 1))) && process->opcode == &direct_store)
		process->params[2 - i] = ft_get_mars_value(mars, address, INDEX);
	else
		process->params[2 - i] = ft_get_mars_value(mars, ft_get_mars_value(mars, address, INDEX) - 1, 1);
	return (INDEX);
}

int			ft_get_params(
		t_processus *process, t_mars *mars, size_t direct_size, unsigned ocp)
{
	int i;
	int code;
	int address;

	i = 2;
	address = process->pc + 2;
	while (i >= 0)
	{
		code = (ocp >> ((i + 1) * 2) & 3);
		if (code == REG_CODE)
			address += ft_stock_reg(process, mars, i, address);
		else if (code == DIR_CODE)
		{
			process->params[2 - i] = ft_get_mars_value(mars,
					address, direct_size);
			address += direct_size;
		}
		else if (code == IND_CODE)
			address += ft_stock_indirect(process, mars, i, address);
		i--;
	}
	process->bytes_to_jump = address;
	return (SUCCESS);
}
