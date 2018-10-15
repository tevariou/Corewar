/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adressage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:29:57 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/15 17:55:12 by abiestro         ###   ########.fr       */
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

int			ft_op_need_restriction(int (*op)(t_mars *, t_processus *))
{
	if (op == &long_direct_load || op == &long_indirect_load ||
		op == &long_fork || op == &jump)
		return (0);
	return (1);
}
