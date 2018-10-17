/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:24:41 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 16:18:40 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_t_reg(t_code *new, int index, bool ocp)
{
	new->size += 1;
	if (ocp)
	{
		if (index == 0)
			new->ocp |= 0x40;
		else if (index == 1)
			new->ocp |= 0x10;
		else if (index == 2)
			new->ocp |= 0x04;
	}
}

void	add_t_dir(t_code *new, int index, bool ocp)
{
	new->size = (dir_len(new->op_code)) ? new->size + 2 : new->size + 4;
	if (ocp)
	{
		if (index == 0)
			new->ocp |= 0x80;
		else if (index == 1)
			new->ocp |= 0x20;
		else if (index == 2)
			new->ocp |= 0x08;
	}
}

void	add_t_ind(t_code *new, int index, bool ocp)
{
	new->size += 2;
	if (ocp)
	{
		if (index == 0)
			new->ocp |= 0xC0;
		else if (index == 1)
			new->ocp |= 0x30;
		else if (index == 2)
			new->ocp |= 0xC;
	}
}
