/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:13:42 by triou             #+#    #+#             */
/*   Updated: 2018/09/23 18:16:30 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

const t_ft_lex	g_ft_lex[FT_LEX_NUMBER] =
{
	{&ft_str_label, L_LAB},
	{&ft_reg, L_REG},
	{&ft_label_str, L_LABEL_STR},
	{&ft_direct, L_DIRECT},
	{&ft_separator, L_SEPARATOR},
	{&ft_number, L_NUM},
	{&ft_op, L_OP},
	{&ft_instruct, L_INSTRUCT},
	{&ft_blanks, L_BLANKS}
};

static void	attribute_tokens(t_asm *a, t_file *line)
{
	char	*str;
	char	*ptr;
	int		i;

	str = line->line;
	while (*str)
	{
		i = 0;
		while (i < FT_LEX_NUMBER)
		{
			if ((ptr = g_ft_lex[i][0](str)))
			{
				add_token(a, line, g_ft_lex[i][1], ft_strndup(str, ptr - str));
				str = ptr;
				break ;
			}
			i++;
		}
		if (i == FT_LEX_NUMBER)
			lex_error(a, line);
	}
}

void		lexer(t_asm *a)
{
	t_file  *line;
	t_file	*tail;

	line = a->input;
	tail = line->prev;
	while (line != tail)
	{
		attribute_tokens(a, line);
		line = line->next;
	}
	attribute_tokens(a, line);
}
