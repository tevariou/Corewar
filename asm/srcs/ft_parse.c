/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 19:40:29 by triou             #+#    #+#             */
/*   Updated: 2018/09/24 22:53:23 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

static t_lex	*traverse_arg(t_file *line, t_lex *list, int type)
{
	t_lex	*end;

	end = line->tokens;
	while (list != end && list->arg_type == type)
			list = list->next;	
	return (list);
}

static t_lex	*is_dir_ind_reg(t_file *line, t_lex *list)
{
	if (list->arg_type == T_DIR)
		list = traverse_arg(line, list, T_DIR);
	else if (list->arg_type == T_IND)
		list = traverse_arg(line, list, T_IND);
	else if (list->arg_type == T_REG)
		list = list->next;
	else
		return (NULL);
	return (list);
}

static t_lex	*is_dir_reg(t_file *line, t_lex *list)
{
	if (list->arg_type == T_DIR)
		list = traverse_arg(line, list, T_DIR);
	else if (list->arg_type == T_REG)
		list = list->next;
	else
		return (NULL);
	return (list);
}

t_bool			ft_parse_0(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if (line->n_args != 1
		|| (list->token == L_BLANKS && (list = list->next) == end))
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
	if (line->n_args != 2
		|| (list->token == L_BLANKS && (list = list->next) == end))
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
	if (line->n_args != 2
		|| (list->token != L_BLANKS || (list = list->next) == end)
		||  (list->arg_type != T_REG || (list = list->next) == end)
		|| (list->token != L_SEPARATOR || (list = list->next) == end)
		|| !(list = is_dir_reg(line, list)))
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
	if (line->n_args != 3
		|| (list->token != L_BLANKS || (list = list->next) == end)
		|| (list->arg_type != T_REG || (list = list->next) == end)
		|| (list->token != L_SEPARATOR || (list = list->next) == end)
		|| (list->arg_type != T_REG || (list = list->next) == end)
		|| (list->token != L_SEPARATOR || (list = list->next) == end)
		|| (list->arg_type != T_REG || (list = list->next) == end))
		return (FALSE);
	*token = list;
	return (TRUE);
}

t_bool			ft_parse_4(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if (line->n_args != 3
		|| (list->token == L_BLANKS && (list = list->next) == end))
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
		|| (list == end || list->token != L_SEPARATOR || (list = list->next) == end
		|| list->arg_type != T_REG))
		return (FALSE);
	*token = list->next;
	return (TRUE);
}

t_bool			ft_parse_5(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if (line->n_args != 3
		|| (list->token == L_BLANKS && (list = list->next) == end))
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
		|| !(list = is_dir_reg(line, list))
		|| (list == end || list->token != L_SEPARATOR || (list = list->next) == end
		|| list->arg_type != T_REG))
		return (FALSE);
	*token = list->next;
	return (TRUE);
}

t_bool			ft_parse_6(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;	
	if (line->n_args != 3
		|| (list->token != L_BLANKS || (list = list->next) == end)
		|| (list->arg_type != T_REG || (list = list->next) == end)
		|| (list->token != L_SEPARATOR || (list = list->next) == end)
		|| !(list = is_dir_ind_reg(line, list))
		|| (list == end || list->token != L_SEPARATOR || (list = list->next) == end)
		|| !(list = is_dir_reg(line, list)))
		return (FALSE);
	*token = list;
	return (TRUE);
}

t_bool			ft_parse_7(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;	
	if (line->n_args != 1
		|| (list->token != L_BLANKS || (list = list->next) == end)
		|| (list->arg_type != T_REG))
		return (FALSE);
	*token = list->next;
	return (TRUE);
}
