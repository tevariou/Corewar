/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:13:42 by triou             #+#    #+#             */
/*   Updated: 2018/09/18 20:36:55 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*(*g_ft_lex[FT_LEX_NUMBER])(char *) =
{
	{&ft_str_label, L_STR_LABEL},
	{&ft_label_str, 
	&ft_direct,
	&ft_separator,
	&ft_reg,
	&ft_op,
	&ft_number,
	&ft_instruct,
	&ft_blanks
}

void	attribute_tokens(t_file *line)
{
	char	*str;
	char	*ptr;

	str = line->line;
	while (*str)
	{
			
		str++;
	}
}

void	lexer(t_asm *a)
{
	t_file  *line;
	t_file	*tail;

	line = a->input;
	tail = head->prev;
	while (line != tail)
	{
		attribute_tokens(line);
		line = line->next;
	}
}
