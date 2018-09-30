/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 17:36:18 by triou             #+#    #+#             */
/*   Updated: 2018/09/30 22:38:34 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	dir_len(t_byte op_code)
{
	int	i;

	i = 0;
	while (g_op_tab[i].op_code != op_code)
		i++;
	return (g_op_tab[i].dir_size);
}

static void		init_bytecode(t_asm *a)
{
	t_file	*list;
	t_file	*tail;

	list = a->input;
	tail = list->prev;
	while (list != tail)
	{
		if (list->n_args)
			add_op(a, list);
		list = list->next;
	}
	if (list->n_args)
		add_op(a, list);
}

static void		set_dir_ind(t_asm *a)
{
	t_code	*list;
	t_code	*tail;

	list = a->output;
	tail = list->prev;
	while (list != tail)
	{
		list = list->next;
	}
}

void			set_bytecode(t_asm *a)
{
	init_bytecode(a);
	set_dir_ind(a);
}
