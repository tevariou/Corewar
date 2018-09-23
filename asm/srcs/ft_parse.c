/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 19:40:29 by triou             #+#    #+#             */
/*   Updated: 2018/09/24 00:03:46 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	ft_parse_0(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if (line->n_args != 1
		|| (list->token == L_BLANKS && (list = list->next) == end))
		return (FALSE);
	while (list != end && list->arg_type == T_DIR)
		list = list->next;
	*token = list;
	return (TRUE);
}

t_bool	ft_parse_1(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if (line->n_args != 2
		|| (list->token == L_BLANKS && (list = list->next) == end))
		return (FALSE);
	if (list->arg_type == T_DIR)
	{
		while (list != end && list->arg_type == T_DIR)
			list = list->next;
	}
	else if (list->prev->token == L_BLANKS && list->arg_type == T_IND)
	{
		while (list != end && list->arg_type == T_IND)
			list = list->next;
	}
	else
		return (FALSE);
	if ((list == end || list->token != L_SEPARATOR)
		|| ((list = list->next) == end || list->arg_type != T_REG))
		return (FALSE);
	*token = list->next;
	return (TRUE);
}

t_bool	ft_parse_2(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if (line->n_args != 2)
		return (FALSE);	
	if ((list->token != L_BLANKS || (list = list->next) == end)
		||  (list->arg_type != T_REG || (list = list->next) == end)
		|| (list->token != L_SEPARATOR || (list = list->next) == end))
		return (FALSE);
	if (list->arg_type == T_DIR)
	{
		while (list != end && list->arg_type == T_DIR)
			list = list->next;
		return (TRUE);
	}
	else if (list->arg_type != T_REG)
		return (FALSE);
	*token = list->next;
	return (TRUE);
}

t_bool	ft_parse_3(t_file *line, t_lex **token)
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

t_lex	*traverse_arg(t_file *line, t_lex *list, int type)
{
	t_lex	*end;

	end = line->tokens;
	while (list != end && list->arg_type == type)
			list = list->next;	
	return (list);
}

t_bool	ft_parse_4(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if (line->n_args != 3)
		return (FALSE);
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
	if (list == end || list->token != L_SEPARATOR || (list = list->next) == end)
		return (FALSE);
	if (list->arg_type == T_DIR)
		list = traverse_arg(line, list, T_DIR);
	else if (list->arg_type == T_IND)
		list = traverse_arg(line, list, T_IND);
	else if (list->arg_type == T_REG)
		list = list->next;
	else
		return (FALSE);
	if (list == end || list->token != L_SEPARATOR || (list = list->next) == end)
		return (FALSE);
	if (list->arg_type != T_REG)
		return (FALSE);
	*token = list->next;
	return (TRUE);
}
