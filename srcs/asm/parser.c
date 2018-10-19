/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 17:36:40 by triou             #+#    #+#             */
/*   Updated: 2018/10/19 14:43:59 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static const t_parse	g_parse_tab[8] = {
	{{"live", "zjmp", "lfork", "fork", 0}, &ft_parse_0, 1},
	{{"ld", "lld", 0}, &ft_parse_1, 2},
	{{"st", 0}, &ft_parse_2, 2},
	{{"add", "sub", 0}, &ft_parse_3, 3},
	{{"and", "or", "xor", 0}, &ft_parse_4, 3},
	{{"ldi", "lldi", 0}, &ft_parse_5, 3},
	{{"sti", 0}, &ft_parse_6, 3},
	{{"aff", 0}, &ft_parse_7, 1}
};

static bool				p_instruct(t_asm *a, t_file *line, t_lex **token)
{
	t_lex	*list;
	int		i;

	list = *token;
	i = 0;
	while (i < 8)
	{
		if (ft_tabequ(g_parse_tab[i].name, list->val))
		{
			if ((*token = list->next) == line->tokens)
				return (false);
			if (g_parse_tab[i].n_args != line->n_args)
				parser_error(a, line, INVALID_ARGS);
			return (g_parse_tab[i].f(line, token));
		}
		i++;
	}
	return (false);
}

static bool				p_blanks(t_lex **token)
{
	t_lex	*list;

	list = *token;
	if (list->token == L_BLANKS)
	{
		*token = list->next;
		return (true);
	}
	return (false);
}

static bool				p_lab(t_lex **token)
{
	t_lex	*list;

	list = *token;
	if (list->token == L_LAB)
	{
		*token = list->next;
		return (true);
	}
	return (false);
}

static void				parse_line(t_asm *a, t_file *line)
{
	t_lex	*list;
	t_lex	*end;

	list = line->tokens;
	end = list;
	if (p_lab(&list))
	{
		if (list == end || (list != end && p_blanks(&list)
			&& p_instruct(a, line, &list) && list == end)
			|| (list != end && p_instruct(a, line, &list)
			&& list == end))
			return ;
	}
	else if (p_instruct(a, line, &list) && list == end)
		return ;
	parser_error(a, line, PARSER_ERROR);
}

void					parser(t_asm *a)
{
	t_file	*line;
	t_file	*tail;

	line = a->input;
	tail = line->prev;
	while (line != tail)
	{
		parse_line(a, line);
		line = line->next;
	}
	parse_line(a, line);
}
