/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 19:40:29 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 16:30:40 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool			ft_parse_0(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if (list->token == L_BLANKS && (list = list->next) == end)
		return (FALSE);
	if (list->arg_type == T_DIR)
		list = traverse_arg(line, list, T_DIR);
	else
		return (FALSE);
	*token = list;
	return (TRUE);
}

t_bool			ft_parse_1(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if (list->token == L_BLANKS && (list = list->next) == end)
		return (FALSE);
	if (list->arg_type == T_DIR)
		list = traverse_arg(line, list, T_DIR);
	else if (list->prev->token == L_BLANKS && list->arg_type == T_IND)
		list = traverse_arg(line, list, T_IND);
	else
		return (FALSE);
	if ((list == end || list->token != L_SEPARATOR)
		|| ((list = list->next) == end || list->arg_type != T_REG))
		return (FALSE);
	*token = list->next;
	return (TRUE);
}

t_bool			ft_parse_2(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if ((list->token != L_BLANKS || (list = list->next) == end)
		|| (list->arg_type != T_REG || (list = list->next) == end)
		|| (list->token != L_SEPARATOR || (list = list->next) == end)
		|| !(list = is_ind_reg(line, list)))
		return (FALSE);
	*token = list;
	return (TRUE);
}

t_bool			ft_parse_3(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if ((list->token != L_BLANKS || (list = list->next) == end)
		|| (list->arg_type != T_REG || (list = list->next) == end)
		|| (list->token != L_SEPARATOR || (list = list->next) == end)
		|| (list->arg_type != T_REG || (list = list->next) == end)
		|| (list->token != L_SEPARATOR || (list = list->next) == end)
		|| list->arg_type != T_REG)
		return (FALSE);
	*token = list->next;
	return (TRUE);
}

t_bool			ft_parse_4(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if (list->token == L_BLANKS && (list = list->next) == end)
		return (FALSE);
	if (list->arg_type == T_DIR)
		list = traverse_arg(line, list, T_DIR);
	else if (list->prev->token == L_BLANKS && list->arg_type == T_IND)
		list = traverse_arg(line, list, T_IND);
	else if (list->prev->token == L_BLANKS && list->arg_type == T_REG)
		list = list->next;
	else
		return (FALSE);
	if (list == end || list->token != L_SEPARATOR || (list = list->next) == end
		|| !(list = is_dir_ind_reg(line, list))
		|| (list == end || list->token != L_SEPARATOR
		|| (list = list->next) == end || list->arg_type != T_REG))
		return (FALSE);
	*token = list->next;
	return (TRUE);
}
