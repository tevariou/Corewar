/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:28:01 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 16:39:39 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

bool			ft_parse_5(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if (list->token == L_BLANKS && (list = list->next) == end)
		return (false);
	if (list->arg_type == T_DIR)
		list = traverse_arg(line, list, T_DIR);
	else if (list->prev->token == L_BLANKS && list->arg_type == T_IND)
		list = traverse_arg(line, list, T_IND);
	else if (list->prev->token == L_BLANKS && list->arg_type == T_REG)
		list = list->next;
	else
		return (false);
	if (list == end || list->token != L_SEPARATOR || (list = list->next) == end
		|| !(list = is_dir_reg(line, list)) || (list == end
		|| list->token != L_SEPARATOR || (list = list->next) == end
		|| list->arg_type != T_REG))
		return (false);
	*token = list->next;
	return (true);
}

bool			ft_parse_6(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if ((list->token != L_BLANKS || (list = list->next) == end)
		|| (list->arg_type != T_REG || (list = list->next) == end)
		|| (list->token != L_SEPARATOR || (list = list->next) == end)
		|| !(list = is_dir_ind_reg(line, list))
		|| (list == end || list->token != L_SEPARATOR
		|| (list = list->next) == end)
		|| !(list = is_dir_reg(line, list)))
		return (false);
	*token = list;
	return (true);
}

bool			ft_parse_7(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if ((list->token != L_BLANKS || (list = list->next) == end)
		|| (list->arg_type != T_REG))
		return (false);
	*token = list->next;
	return (true);
}
