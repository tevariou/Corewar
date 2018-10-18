/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:13:42 by triou             #+#    #+#             */
/*   Updated: 2018/10/10 12:07:50 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>

static const t_ft_lex	g_ft_lex[FT_LEX_NUMBER] =
{
	{&ft_str_label, L_LAB},
	{&ft_reg, L_REG},
	{&ft_label_str, L_LABEL_STR},
	{&ft_direct, L_DIRECT},
	{&ft_separator, L_SEPARATOR},
	{&ft_number, L_NUM},
	{&ft_instruct, L_INSTRUCT},
	{&ft_blanks, L_BLANKS}
};

static void	add_token(t_asm *a, t_file *line, t_tok token, char *val)
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

static void	attribute_tokens(t_asm *a, t_file *line)
{
	char	*str;
	char	*ptr;
	size_t	size;
	int		i;

	str = line->line;
	while (*str)
	{
		i = 0;
		while (i < FT_LEX_NUMBER)
		{
			if ((ptr = g_ft_lex[i].f(str)))
			{
				size = ptr - str;
				add_token(a, line, g_ft_lex[i].token, ft_strndup(str, size));
				str = ptr;
				break ;
			}
			i++;
		}
		if (i == FT_LEX_NUMBER)
			asm_error(a, line, str, LEXER_ERROR);
	}
}

void		lexer(t_asm *a)
{
	t_file	*line;
	t_file	*tail;

	if (!(line = a->input))
		err_free_exit(a, NO_INSTRUCTION);
	tail = line->prev;
	while (line != tail)
	{
		attribute_tokens(a, line);
		line = line->next;
	}
	attribute_tokens(a, line);
}
