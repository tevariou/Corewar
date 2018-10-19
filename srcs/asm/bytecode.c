/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 17:36:18 by triou             #+#    #+#             */
/*   Updated: 2018/10/19 18:38:48 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static unsigned short	convert_short(t_asm *a, t_code *op, char *str)
{
	if (*str == LABEL_CHAR)
		return (convert_label_short(a, op, str));
	else if (ft_strnequ(str, "0x", 2) || ft_strnequ(str, "0X", 2))
		return (atoi_base_short(str + 2, HEXA));
	else
		return (atoi_base_short(str, DEC));
}

static unsigned int		convert_int(t_asm *a, t_code *op, char *str)
{
	if (*str == LABEL_CHAR)
		return (convert_label_int(a, op, str));
	else if (ft_strnequ(str, "0x", 2) || ft_strnequ(str, "0X", 2))
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
			op->args[i].u16 = convert_short(a, op, op->values[i]);
		else if (op->args_type[i] == T_DIR && !dir_len(op->op_code))
			op->args[i].u32 = convert_int(a, op, op->values[i]);
		else
			op->args[i].u32 = 0;
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

void					set_bytecode(t_asm *a)
{
	init_bytecode(a);
	if (!(a->output))
		err_free_exit(a, NO_INSTRUCTION);
	set_values(a);
}
