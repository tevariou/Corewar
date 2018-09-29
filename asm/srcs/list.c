/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:24:41 by triou             #+#    #+#             */
/*   Updated: 2018/09/29 16:23:55 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

void			add_input_line(t_asm *a, char *line, size_t n)
{
	t_file	*head;
	t_file	*new;
	t_file	*tail;

	if (!(new = ft_memalloc(sizeof(*new))))
		err_free_exit(a, NULL);
	new->line = line;
	new->n = n;
	new->tokens = NULL;
	if (!(head = a->input))
	{
		new->prev = new;
		new->next = new;
		a->input = new;
		return ;
	}
	tail = head->prev;
	tail->next = new;
	new->prev = tail;
	new->next = head;
	head->prev = new;
}

void			add_token(t_asm *a, t_file *line, t_tok token, char *val)
{
	t_lex	*new;
	t_lex	*head;
	t_lex	*tail;

	new = NULL;
	if (!val || !(new = ft_memalloc(sizeof(*new))))
		err_free_exit(a, NULL);	
	new->token = token;
	new->val = val;
	if (!(head = line->tokens))
	{
		new->prev = new;
		new->next = new;
		line->tokens = new;
		return ;	
	}
	tail = head->prev;
	tail->next = new;
	new->prev = tail;
	new->next = head;
	head->prev = new;
}

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

void			add_label(t_asm *a, t_file *list)
{
	t_lab	*new;
	t_lab	*head;
	t_lab	*tail;

	if (!(new = ft_memalloc(sizeof(*new))))
		err_free_exit(a, NULL);
	new->target = get_target(a, list);
	new->name = list->val;
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
