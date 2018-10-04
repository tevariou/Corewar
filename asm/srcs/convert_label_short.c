/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_label_short.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:34:57 by triou             #+#    #+#             */
/*   Updated: 2018/10/03 23:25:21 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "asm.h"

static unsigned short	compute_len_short(t_asm *a, t_code *orig, t_code *target)
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
			reverse_bytes(&ret, sizeof(ret));
			return (ret);
		}
		if ((len += tmp->size) > SHRT_MAX)
			err_free_exit(a, FILE_OVERFLOW);
		tmp = tmp->next;
	}
	if (tmp == target)
	{
		ret = (unsigned short)len;
		reverse_bytes(&ret, sizeof(ret));
		return (ret);
	}
	len = 0;
	tmp = orig->prev;
	tail = a->output;
	while (tmp != tail)
	{
		if ((len -= tmp->size) < SHRT_MIN)
			err_free_exit(a, FILE_OVERFLOW);
		if (tmp == target)
		{
			ret = (unsigned short)len;
			reverse_bytes(&ret, sizeof(ret));
			return (ret);
		}
		tmp = tmp->prev;
	}
	if ((len -= tmp->size) < SHRT_MIN)
		err_free_exit(a, FILE_OVERFLOW);
	if (tmp == target)
	{
		ret = (unsigned short)len;
		reverse_bytes(&ret, sizeof(ret));
		return (ret);
	}
	return (0);
}

static unsigned short label_null_short(t_asm *a, t_code *orig)
{
	ssize_t			len;
	unsigned short	ret;
	t_code			*tail;

	len = 0;
	tail = a->output->prev;
	while (orig != tail)
	{
		if ((len += orig->size) > SHRT_MAX)
			err_free_exit(a, FILE_OVERFLOW);
		orig = orig->next;
	}
	if ((len += orig->size) > SHRT_MAX)
			err_free_exit(a, FILE_OVERFLOW);
	ret = (unsigned short)len;
	reverse_bytes(&ret, sizeof(ret));
	return (ret);
}

static unsigned short	label_address_short(t_asm *a, t_label *label, t_code *orig, char *str)
{
	t_code			*target;
	t_code			*tail;

	if (!(label->target))
		return (label_null_short(a, orig));
	target = a->output;
	tail = target->prev;
	while (target != tail)
	{
		if (target->orig == label->target)
			return (compute_len_short(a, orig, target));
		target = target->next;
	}
	if (target->orig == label->target)
		return (compute_len_short(a, orig, target));
	label_error(a, orig->orig, str);
	return (0);
}

unsigned short			convert_label_short(t_asm *a, t_code *op, char *str)
{
	t_label	*label;
	t_label	*tail;

	if(!(label = a->labels))
		label_error(a, op->orig, str);
	tail = label->prev;
	while (label != tail)
	{
		if (ft_strnequ(str + 1, label->name, ft_strlen(label->name) - 1))
			return (label_address_short(a, label, op, str));
		label = label->next;	
	}
	if (ft_strnequ(str + 1, label->name, ft_strlen(label->name) - 1))
		return (label_address_short(a, label, op, str));
	label_error(a, op->orig, str);
	return (0);
}
