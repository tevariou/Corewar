/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:57:14 by triou             #+#    #+#             */
/*   Updated: 2018/10/02 15:56:34 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <limits.h>

unsigned short	compute_len(t_asm *a, t_code *orig, t_code *target)
{
	ssize_t			len;
	unsigned short	ret;
	t_code			*tmp;	
	t_code			*tail;

	len = 0;
	tmp = orig;
	tail = a->output->prev;
	while (tmp != tail)
	{
		if (tmp == target)
		{
			ret = (unsigned short)len;
			reverse_bytes(&ret);
			return (ret);
		}
		if ((len += tmp->size) > SHRT_MAX)
			err_free_exit(a, FILE_OVERFLOW);
		tmp = tmp->next;
	}
	if (tmp == target)
	{
		ret = (unsigned short)len;
		reverse_bytes(&ret);
		return (ret);
	}
	len = 0;
	tmp = orig;
	tail = a->output;
	while (tmp != tail)
	{
		if (tmp == target)
		{
			ret = (unsigned short)len;
			reverse_bytes(&ret);
			return (ret);
		}
		if ((len -= tmp->size) < SHRT_MIN)
			err_free_exit(a, FILE_OVERFLOW);
		tmp = tmp->prev;
	}
	if (tmp == target)
	{
		ret = (unsigned short)len;
		reverse_bytes(&ret);
		return (ret);
	}
	return (0);
}

unsigned short	label_address(t_asm *a, t_label *label, t_code *orig, char *str)
{
	t_code			*target;
	t_code			*tail;
	unsigned short	ret;

	target = a->output;
	tail = target->prev;
	while (target != tail)
	{
		if (target->orig == label->target)
			return (compute_len(a, orig, target));
		target = target->next;
	}
	if (target->orig == label->target)
		return (compute_len(a, orig, target));
	label_error(a, orig->orig, str);
	return (0);
}

unsigned short	convert_label_ind(t_asm *a, t_code *op, char *str)
{
	t_label	*label;
	t_label	*tail;

	if(!(label = a->labels))
		label_error(a, op->orig, str);
	tail = label->prev;
	while (label != tail)
	{
		if (ft_strequ(str, label->name))
			return (label_address(a, label, op, str));
		label = label->next;	
	}
	if (ft_strequ(str, label->name))
		return (label_adress(a, label, op, str));
	label_error(a, op->orig, str);
	return (0);
}

void			get_labels(t_asm *a)
{
	t_file	*list;
	t_file	*tail;

	list = a->input;
	tail = list->prev;
	while (list != tail)
	{
		if (list->tokens->token == L_LAB)
			add_label(a, list);
		list = list->next;
	}
	if (list->tokens->token == L_LAB)
		add_label(a, list);
}
