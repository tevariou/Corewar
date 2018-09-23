/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 19:40:29 by triou             #+#    #+#             */
/*   Updated: 2018/09/23 20:37:06 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	ft_parse_0(t_file *line, t_lex **token)
{
	t_lex	*list;
	t_lex	*end;

	list = *token;
	end = line->tokens;
	if (line->n_args != 1)
		return (FALSE);
	if (list->token == L_BLANKS && (list = list->next) == end)
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
	if (line->n_args != 2)
		return (FALSE);
	if (list->token == L_BLANKS && (list = list->next) == end)
		return (FALSE);
	if (list->arg_type == T_DIR)
	{
		while (list != end && list->arg_type == T_DIR)
			list = list->next;
	}
	else if (list->arg_type == T_IND)
	{
		while (list != end && list->arg_type == T_IND)
			list = list->next;
	}
	else
		return (FALSE);
	if (list == end || list->token != L_SEPARATOR)
		return (FALSE);
	if ((list = list->next) == end || list->arg_type != T_REG)
		return (FALSE);
	*token = list;
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

}
