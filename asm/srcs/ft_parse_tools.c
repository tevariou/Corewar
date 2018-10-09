/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:23:44 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 16:40:01 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

t_lex	*traverse_arg(t_file *line, t_lex *list, int type)
{
	t_lex	*end;

	end = line->tokens;
	while (list != end && list->arg_type == type)
		list = list->next;
	return (list);
}

t_lex	*is_dir_ind_reg(t_file *line, t_lex *list)
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

t_lex	*is_dir_reg(t_file *line, t_lex *list)
{
	if (list->arg_type == T_DIR)
		list = traverse_arg(line, list, T_DIR);
	else if (list->arg_type == T_REG)
		list = list->next;
	else
		return (NULL);
	return (list);
}

t_lex	*is_ind_reg(t_file *line, t_lex *list)
{
	if (list->arg_type == T_IND)
		list = traverse_arg(line, list, T_IND);
	else if (list->arg_type == T_REG)
		list = list->next;
	else
		return (NULL);
	return (list);
}
