/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 17:36:18 by triou             #+#    #+#             */
/*   Updated: 2018/10/02 15:52:08 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool					dir_len(t_byte op_code)
{
	int	i;

	i = 0;
	while (g_op_tab[i].op_code != op_code)
		i++;
	return (g_op_tab[i].dir_size);
}

static void				init_bytecode(t_asm *a)
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

static unsigned short	convert_ind(t_asm *a, t_code *op, char *str)
{
	if (*str == LABEL_CHAR)
		return (convert_label_ind(a, op, str));
	else if (ft_strnequ(str, "0x", 2))
		return (atoi_base_short(str + 2, HEXA));
	else
		return (atoi_base_short(str, DEC));
}

static unsigned int		convert_dir(t_asm *a, t_code *op, char *str)
{
	if (*str == LABEL_CHAR && !dir_len(op->op_code))
		return (convert_label_dir(a, op, str));
	else if (*str == LABEL_CHAR)
		return (convert_label_ind(a, op, str));
	else if (ft_strnequ(str, "0x", 2))
		return (atoi_base_int(str + 2, HEXA));
	else
		return (atoi_base_int(str, DEC));
}

static void				convert_values(t_asm *a, t_code *op)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (op->args_type[i] == T_REG)
			op->args[i].u8 = atoi_reg(a, op, op->values[i]);			
		else if (op->args_type[i] == T_IND
			|| (op->args_type[i] == T_DIR && dir_len(op->op_code)))
			op->args[i].u16 = convert_ind(a, op, op->values[i]);
		else if (op->args_type[i] == T_DIR && !dir_len(op->op_code))
			op->args[i].u32 = convert_dir(a, op, op->values[i]);
		i++;
	}
}

static void				set_values(t_asm *a)
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

void		set_bytecode(t_asm *a)
{
	init_bytecode(a);
	set_values(a);
}
