/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bytecode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:11:57 by triou             #+#    #+#             */
/*   Updated: 2018/10/12 19:47:40 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>

static int	get_opcode(t_code *new, t_lex *list)
{
	int		i;

	while (list->token != L_INSTRUCT)
		list = list->next;
	i = 0;
	while (!ft_strequ(g_op_tab[i].name, list->val))
		i++;
	new->op_code = g_op_tab[i].op_code;
	return (i);
}

static void	get_op_ocp_size(t_code *new, t_lex *list)
{
	int	i;
	int	j;

	new->ocp = 0;
	i = get_opcode(new, list);
	new->size = (g_op_tab[i].ocp) ? 2 : 1;
	j = 0;
	while (j < 3)
	{
		if (new->args_type[j] == T_REG)
			add_t_reg(new, j, g_op_tab[i].ocp);
		else if (new->args_type[j] == T_DIR)
			add_t_dir(new, j, g_op_tab[i].ocp);
		else if (new->args_type[j] == T_IND)
			add_t_ind(new, j, g_op_tab[i].ocp);
		j++;
	}
}

static void	get_args_type(t_code *new, t_lex *head)
{
	t_lex	*list;
	int		i;

	list = head;
	i = 0;
	if (list->arg_type)
	{
		if (list->token == L_DIRECT)
			list = list->next;
		new->args_type[i] = list->arg_type;
		new->values[i++] = list->val;
	}
	list = list->next;
	while (list != head)
	{
		if (list->arg_type)
		{
			if (list->token == L_DIRECT)
				list = list->next;
			new->args_type[i] = list->arg_type;
			new->values[i++] = list->val;
		}
		list = list->next;
	}
}

static void	add_op(t_asm *a, t_file *list)
{
	t_code	*new;
	t_code	*head;
	t_code	*tail;

	if (!(new = ft_memalloc(sizeof(*new))))
		err_free_exit(a, NULL);
	ft_bzero(new->args_type, 3 * sizeof(int));
	ft_bzero(new->values, 3 * sizeof(char *));
	get_args_type(new, list->tokens);
	get_op_ocp_size(new, list->tokens);
	new->orig = list;
	if (!(head = a->output))
	{
		new->prev = new;
		new->next = new;
		a->output = new;
		return ;
	}
	tail = head->prev;
	tail->next = new;
	new->prev = tail;
	new->next = head;
	head->prev = new;
}

void		init_bytecode(t_asm *a)
{
	t_file	*list;
	t_file	*tail;

	list = a->input;
	tail = list->prev;
	while (list != tail)
	{
		if (list->n_args)
			add_op(a, list);
		list = list->next;
	}
	if (list->n_args)
		add_op(a, list);
}
