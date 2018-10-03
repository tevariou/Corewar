/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:30:06 by triou             #+#    #+#             */
/*   Updated: 2018/10/03 19:58:59 by triou            ###   ########.fr       */
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

static void	free_input(t_file *head)
{
	t_file	*tail;
	t_file	*tmp;

	tail = head->prev;
	while (head != tail)
	{
		tmp = head;
		head = head->next;
		free(tmp->line);
		free_tokens(tmp);
		free(tmp);
	}
	free(head->line);
	free_tokens(head);
	free(head);
}

static void	free_labels(t_label *head)
{
	t_label	*tail;
	t_label	*tmp;

	tail = head->prev;
	while (head != tail)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}

static void	free_output(t_code *head)
{
	t_code	*tail;
	t_code	*tmp;

	tail = head->prev;
	while (head != tail)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}

void		free_all(t_asm *a)
{
	if (a->input)
		free_input(a->input);
	if (a->labels)
		free_labels(a->labels);
	if (a->output)
		free_output(a->output);
}
