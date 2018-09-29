/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:57:14 by triou             #+#    #+#             */
/*   Updated: 2018/09/29 15:51:32 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_labels(t_asm *a)
{
	t_file	*list;
	t_file	*tail;

	list = a->input;
	tail = list->prev;
	while (list != tail)
	{
		if (list->tokens->token == L_LAB)
			add_label(a, list);
		list = list->next;
	}
	if (list->tokens->token == L_LAB)
		add_label(a, list);
}
