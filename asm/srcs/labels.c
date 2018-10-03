/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:57:14 by triou             #+#    #+#             */
/*   Updated: 2018/10/03 21:26:49 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool	do_label_exist(t_label *list, char *str)
{
	t_label	*tail;

	if (!list)
		return (FALSE);
	tail = list->prev;
	while (list != tail)
	{
		if (ft_strequ(list->name, str))
			return (TRUE);
		list = list->next;
	}
	if (ft_strequ(list->name, str))
			return (TRUE);
	return (FALSE);
}

void			get_labels(t_asm *a)
{
	t_file	*list;
	t_file	*tail;

	list = a->input;
	tail = list->prev;
	while (list != tail)
	{
		if (list->tokens->token == L_LAB
			&& !do_label_exist(a->labels, list->tokens->val))
			add_label(a, list);
		list = list->next;
	}
	if (list->tokens->token == L_LAB
		&& !do_label_exist(a->labels, list->tokens->val))
		add_label(a, list);
}
