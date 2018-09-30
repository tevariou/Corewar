/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 17:36:18 by triou             #+#    #+#             */
/*   Updated: 2018/09/30 23:51:31 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool			dir_len(t_byte op_code)
{
	int	i;

	i = 0;
	while (g_op_tab[i].op_code != op_code)
		i++;
	return (g_op_tab[i].dir_size);
}

static void		init_bytecode(t_asm *a)
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

static char		convert_reg(t_asm *a, t_code *op, char *str)
{
	char	reg;

	str += 1;
	reg = 0;
	while (ft_isdigit(*str))
	{
		reg *= 10;
		reg += *str++ - '0';
		if (reg > REG_NUMBER)
			asm_error(a, op->orig, WRONG_REG_NUMBER); 
	}
	if (!reg)
		asm_error(a, op->orig, WRONG_REG_NUMBER);
	return (reg);
}

static short	convert_ind(t_asm *a, t_code *op, char *str)
{
	short	ind;

	//
}

static void		convert_values(t_asm *a, t_code *op)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (op->args_type[i] == T_REG)
			op->args[i] = convert_reg(a, op, op->values[i]);			
		else if (op->args_type[i] == T_IND)
			op->args[i] = convert_ind(a, op, op->values[i]);
//		else if
//		T_DIR
		i++;
	}
}

static void		set_num(t_asm *a)
{
	t_code	*list;
	t_code	*tail;

	list = a->output;
	tail = list->prev;
	while (list != tail)
	{
		convert_values(a, list);	
		list = list->next;
	}
	convert_values(a, list);
}

void			set_bytecode(t_asm *a)
{
	init_bytecode(a);
	set_num(a);
}
