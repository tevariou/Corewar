/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:24:41 by triou             #+#    #+#             */
/*   Updated: 2018/10/02 14:22:35 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

void			add_input_line(t_asm *a, char *line, size_t n)
{
	t_file	*head;
	t_file	*new;
	t_file	*tail;

	if (!(new = ft_memalloc(sizeof(*new))))
		err_free_exit(a, NULL);
	new->line = line;
	new->n = n;
	new->tokens = NULL;
	if (!(head = a->input))
	{
		new->prev = new;
		new->next = new;
		a->input = new;
		return ;
	}
	tail = head->prev;
	tail->next = new;
	new->prev = tail;
	new->next = head;
	head->prev = new;
}

void			add_token(t_asm *a, t_file *line, t_tok token, char *val)
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

static t_file	*get_target(t_asm *a, t_file *list)
{
	t_file	*tail;

	tail = a->input->prev;
	while (list != tail && !(list->n_args))
		list = list->next;
	if (list == tail && !(list->n_args))
		list = NULL;
	return (list);
}

void			add_label(t_asm *a, t_file *list)
{
	t_label	*new;
	t_label	*head;
	t_label	*tail;

	if (!(new = ft_memalloc(sizeof(*new))))
		err_free_exit(a, NULL);
	new->target = get_target(a, list);
	new->name = list->val;
	if (!(head = a->labels))
	{
		new->prev = new;
		new->next = new;
		a->labels = new;
		return ;
	}
	tail = head->prev;
	tail->next = new;
	new->prev = tail;
	new->next = head;
	head->prev = new;
}

static int		get_opcode(t_code *new, t_lex *list)
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

static void		get_args_type(t_code *new, t_lex *head)
{
	t_lex	*list;
	int		i;

	list = head;
	i = 0;
	ft_bzero(new->args_type, 3 * sizeof(int));
	ft_bzero(new->values, 3 * sizeof(char *));
	if (list->arg_type)
	{
		if (list->token == L_DIRECT)
			list = list->next;
		new->args_type[i] = list->arg_type;
		new->values[i] = list->val;
		i++;
	}
	list = list->next;
	while (list != head)
	{
		if (list->arg_type)
		{
			if (list->token == L_DIRECT)
				list = list->next;
			new->args_type[i] = list->arg_type;
			new->values[i] = list->val;
			i++;
		}
		list = list->next;
	}
}

static void		add_t_reg(t_code *new, int index, t_bool ocp)
{
	new->size += 1;
	if (ocp)
	{
		if (index == 0)
			new->ocp |= 0x40;
		else if (index == 1)
			new->ocp |= 0x10;
		else if (index == 2)
			new->ocp |= 0x04;
	}
}

static void		add_t_dir(t_code *new, int index, t_bool ocp)
{
	new->size = (dir_len(new->op_code)) ? new->size + 2 : new->size + 4;
	if (ocp)
	{
		if (index == 0)
			new->ocp |= 0x80;
		else if (index == 1)
			new->ocp |= 0x20;
		else if (index == 2)
			new->ocp |= 0x08;
	}
}

static void		add_t_ind(t_code *new, int index, t_bool ocp)
{
	new->size += 2;
	if (ocp)
	{
		if (index == 0)
			new->ocp |= 0xC0;
		else if (index == 1)
			new->ocp |= 0x30;
		else if (index == 2)
			new->ocp |= 0xC;	
	}
}

static void		get_op_ocp_size(t_code *new, t_lex *list)
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

void			add_op(t_asm *a, t_file *list)
{
	t_code	*new;
	t_code	*head;
	t_code	*tail;

	if (!(new = ft_memalloc(sizeof(*new))))
		err_free_exit(a, NULL);
	get_args_type(new, list->tokens);
	get_op_ocp_size(new, list->tokens);
	new->orig = list;
	if (!(head = a->output))
	{
		new->prev = new;
		new->next = new;
		a->labels = new;
		return ;
	}
	tail = head->prev;
	tail->next = new;
	new->prev = tail;
	new->next = head;
	head->prev = new;
}
