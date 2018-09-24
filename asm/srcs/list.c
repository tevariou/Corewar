/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:24:41 by triou             #+#    #+#             */
/*   Updated: 2018/09/24 17:49:05 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

void		add_input_line(t_asm *a, char **line, size_t n)
{
	t_file	*head;
	t_file	*new;
	t_file	*tail;

	if (!(new = ft_memalloc(sizeof(*new))))
		err_free_exit(a, NULL);
	new->line = *line;
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

void	add_token(t_asm *a, t_file *line, t_tok token, char *val)
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
