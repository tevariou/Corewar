/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:51:15 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 16:51:51 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		is_dir_ind(t_file *line, t_lex **tokens)
{
	t_lex	*list;

	list = *tokens;
	line->n_args += 1;
	if (list->token == L_DIRECT)
	{
		list->arg_type = T_DIR;
		list->next->arg_type = T_DIR;
		*tokens = list->next->next;
		return ;
	}
	list->arg_type = T_IND;
	*tokens = list->next;
}

static void		set_arg(t_file *line, t_lex **tokens)
{
	t_lex	*list;

	list = *tokens;
	list->arg_type = 0;
	if (list->token == L_REG)
	{
		list->arg_type = T_REG;
		line->n_args += 1;
		*tokens = list->next;
	}
	else if ((list->token == L_DIRECT
		&& list->next != line->tokens
		&& (list->next->token == L_LABEL_STR
		|| list->next->token == L_NUM))
		|| list->token == L_LABEL_STR
		|| list->token == L_NUM)
		is_dir_ind(line, tokens);
	else
		*tokens = list->next;
}

static void		parse_tokens(t_file *line)
{
	t_lex	*list;

	list = line->tokens;
	line->n_args = 0;
	set_arg(line, &list);
	while (list != line->tokens)
		set_arg(line, &list);
}

void			redux(t_asm *a)
{
	t_file	*list;
	t_file	*tail;

	list = a->input;
	tail = list->prev;
	while (list != tail)
	{
		parse_tokens(list);
		list = list->next;
	}
	parse_tokens(list);
}
