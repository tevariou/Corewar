/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:57:14 by triou             #+#    #+#             */
/*   Updated: 2018/10/19 14:42:42 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>

static t_file	*get_target(t_asm *a, t_file *list)
{
	t_file	*tail;

	tail = a->input->prev;
	while (list != tail && !(list->n_args))
		list = list->next;
	if (list == tail && !(list->n_args))
		list = NULL;
	return (list);
}

static void		add_label(t_asm *a, t_file *list)
{
	t_label	*new;
	t_label	*head;
	t_label	*tail;

	if (!(new = ft_memalloc(sizeof(*new))))
		err_free_exit(a, NULL);
	new->target = get_target(a, list);
	new->name = list->tokens->val;
	if (!(head = a->labels))
	{
		new->prev = new;
		new->next = new;
		a->labels = new;
		return ;
	}
	tail = head->prev;
	tail->next = new;
	new->prev = tail;
	new->next = head;
	head->prev = new;
}

static bool		do_label_exist(t_label *list, char *str)
{
	t_label	*tail;

	ft_strclr(ft_strchr(str, LABEL_CHAR));
	if (!list)
		return (false);
	tail = list->prev;
	while (list != tail)
	{
		if (ft_strequ(list->name, str))
			return (true);
		list = list->next;
	}
	if (ft_strequ(list->name, str))
		return (true);
	return (false);
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
