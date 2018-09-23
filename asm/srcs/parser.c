/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 17:36:40 by triou             #+#    #+#             */
/*   Updated: 2018/09/23 20:45:30 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

const t_parse	g_parse_tab[9] = {
	{{"live", "zjmp", "fork", "lfork", 0}, &ft_parse_0},
	{{"ld", 0}, &ft_parse_1},
	{{"st", 0}, &ft_parse_2},
	{{"add", "sub", 0}, &ft_parse_3},
	{{"and", "or", "xor", 0}, &ft_parse_4},
	{{"ldi", "lldi", 0}, &ft_parse_5},
	{{"sti", 0}, &ft_parse_6},
	{{"aff", 0}, &ft_parse_7},
	{{0}, 0}
};

static t_bool	ft_tabequ(char **tab, char *needle)
{
	while (*tab)
	{
		if (ft_strequ(*tab, needle))
			return (TRUE);
		tab++;
	}
	return (FALSE);	
}

static t_bool	p_instruct(t_file *line, t_lex **token)
{
	t_lex	*list;
	int		i;

	list = *token;
	i = 0;	
	while (i < 9)
	{
		if (ft_tabequ(g_parse_tab[i][0], list->val))
		{
			if ((*token = list->next) == line->tokens)
				return (FALSE);
			return (g_parse_tab[i][1](line, token));
		}
		i++;
	}
	return (FALSE);
}

static t_bool	p_blanks(t_lex **token)
{
	t_lex	*list;

	list = *token;
	if (list->token == L_BLANKS)
	{
		*token = list->next;
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	p_lab(t_lex **token)
{
	t_lex	*list;

	list = *token;
	if (list->token == L_LAB)
	{
		*token = list->next;
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	parse_line(t_file *line)
{
	t_lex	*list;
	t_lex	*end;

	list = line->tokens;
	end = list;
	if (p_lab(&list))
	{
		if (list != line->tokens && p_blanks(&list) && p_instruct(&list) && list == end)
			return (TRUE);
		else if (list != line->tokens && p_instruct(line, &list) && list == end)
			return (TRUE);
	}
	else if (p_instruct(line, &list) && list == end)
		return (TRUE);
	return (FALSE);
}

void			parser(t_asm *a)
{
	t_file	*line;
	t_file	*tail;

	line = a->input;
	tail = line->prev;
	while (line != tail)
	{
		if (!parse_line(line))
			parse_error(a, line);
		line = line->next;
	}
	if (!parse_line(line))
		parse_error(a, line);
}
