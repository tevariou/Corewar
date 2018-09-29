/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ocp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:14:56 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/29 19:50:12 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include "libft.h"
#include <stdio.h>

int		ft_get_ocp(t_processus *process, unsigned ocp)
{
	process->define_params[0] = ocp >> 2 & 3;
	process->define_params[1] = ocp >> 4 & 3;
	process->define_params[2] = ocp >> 6 & 3;
	return (SUCCESS);
}

int		ft_save_directs(t_processus *process, t_mars *mars, size_t id, size_t count)
{
	unsigned int	res;
	unsigned int	tmp;

	res = 0;
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

int		ft_get_params(t_processus *process, t_mars *mars, size_t direct_size)
{
	size_t			i;
	size_t			count;

	i = 0;
	count = 2;
	while (i < 3)
	{
		if (process->define_params[i] == REG_CODE)
		{
			process->size_params[i] = REG;
			count++;
			// count += ft_save_registres(mars, process, i, count);
		}
		else if (process->define_params[i] == DIR_CODE)
		{
			process->size_params[i] = direct_size;
			count += ft_save_directs(process, mars, i, count);
		}
		else if (process->define_params[i] == IND_CODE)
		{
			process->size_params[i] = INDEX;
			// count += ft_save_indirects(mars, process, i, count);
		}
		i++;
	}
	return (SUCCESS);
}
