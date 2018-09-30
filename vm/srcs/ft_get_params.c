/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:14:56 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/30 16:49:59 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include <stdio.h>

static int		ft_get_ocp(t_processus *process, unsigned ocp)
{
	process->define_params[2] = ocp >> 2 & 3;
	process->define_params[1] = ocp >> 4 & 3;
	process->define_params[0] = ocp >> 6 & 3;
	return (SUCCESS);
}

static int		ft_save_indirects_direct2(t_processus *process, t_mars *mars,
	size_t id, size_t count)
{
	unsigned int	res;
	unsigned int	tmp;

	res = 0;
	tmp = mars->memory[process->pc + count] << 8;
	res += tmp & 0x0000FF00;
	tmp = mars->memory[process->pc + count + 1];
	res += tmp & 0x000000FF;
	process->params[id] = res;
	return (2);
}

static int		ft_save_directs(t_processus *process, t_mars *mars,
	size_t id, size_t count)
{
	unsigned int	res;
	unsigned int	tmp;

	res = 0;
	if (process->size_params[id] == 4)
	{
		tmp = mars->memory[process->pc + count] << 24;
		res = tmp & 0xFF000000;
		tmp = mars->memory[process->pc + count + 1] << 16;
		res += tmp & 0x00FF0000;
		tmp = mars->memory[process->pc + count + 2] << 8;
		res += tmp & 0x0000FF00;
		tmp = mars->memory[process->pc + count + 3];
		res += tmp & 0x000000FF;
		process->params[id] = res;
		return (4);
	}
	else
		return (ft_save_indirects_direct2(process, mars, id, count));

}

static int		ft_save_registers(t_processus *process, t_mars *mars,
	size_t id, size_t count)
{
	process->params[id] = mars->memory[process->pc + count];
	return (1);
}

int		ft_get_params(t_processus *process, t_mars *mars, size_t direct_size,
	unsigned ocp)
{
	size_t			i;
	size_t			count;

	i = -1;
	count = 2;
	ft_get_ocp(process, ocp);
	while (++i < 3)
	{
		if (process->define_params[i] == REG_CODE)
		{
			process->size_params[i] = REG;
			count += ft_save_registers(process, mars, i, count);
		}
		else if (process->define_params[i] == DIR_CODE)
		{
			process->size_params[i] = direct_size;
			count += ft_save_directs(process, mars, i, count);
		}
		else if (process->define_params[i] == IND_CODE)
		{
			process->size_params[i] = INDEX;
			count += ft_save_indirects_direct2(process, mars, i, count);
		}
	}
	printf("REGISTER == 1 || DIRECT == 2 || INDIRECT == 3\n");
	printf(" define_param = %d params[0] %u\n", process->define_params[0], process->params[0]);
	printf(" define_param = %d params[1] %u\n", process->define_params[1], process->params[1]);
	printf(" define_param = %d params[2] %u\n", process->define_params[2], process->params[2]);
	return (SUCCESS);
}
