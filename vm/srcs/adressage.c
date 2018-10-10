/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adressage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:29:57 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/10 16:55:32 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

unsigned	ft_global_restriction(unsigned address)
{
	if (address >= MEM_SIZE)
	{
		address %= MEM_SIZE;
	}
	return (address);
}

unsigned	ft_local_restriction(unsigned pc, unsigned target)
{
	int dest;

	dest = 0;
	dest += target;
	dest %= IDX_MOD;
	if (target % IDX_MOD >  IDX_MOD / 2)
	{
		dest -= IDX_MOD;
	}
	return (dest + pc);
}

int	ft_op_need_restriction(int (*op)(t_mars *, t_processus *))
{
	if (op == &long_direct_load || op == &long_indirect_load || 
		op == &long_fork || op == &jump)
		return (0);
	return (1);
}
