/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:30:06 by triou             #+#    #+#             */
/*   Updated: 2018/09/24 19:30:20 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

static void	free_tokens(t_file *l)
{
	t_lex	*head;
	t_lex	*tail;
	t_lex	*tmp;

	if (!(head = l->tokens))
		return ;
	tail = l->tokens->prev;
	while (head != tail)
	{
		tmp = head;
		head = head->next;
		free(tmp->val);
		free(tmp);
	}
	free(head->val);
	free(head);
	l->tokens = NULL;
}

void		free_input(t_asm *a)
{
	t_file	*head;
	t_file	*tail;
	t_file	*tmp;

	if (!(head = a->input))
		return ;
	tail = a->input->prev;
	while (head != tail)
	{
		tmp = head;
		head = head->next;
		free(tmp->line);
		free_tokens(tmp);
		free(tmp);
	}
	free(head->line);
	free(head);
	a->input = NULL;
}
