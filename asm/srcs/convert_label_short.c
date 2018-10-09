/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_label_short.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:34:57 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 20:05:41 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "asm.h"

static unsigned short	return_short_value(ssize_t len)
{
	unsigned short	ret;

	ret = (unsigned short)len;
	reverse_bytes(&ret, sizeof(ret));
	return (ret);
}

static unsigned short	compute_len_short(t_asm *a, t_code *orig,
											t_code *target)
{
	ssize_t	len;
	t_code	*tmp;

	len = 0;
	tmp = orig;
	while (tmp != a->output->prev)
	{
		if (tmp == target)
			return (return_short_value(len));
		if ((len += tmp->size) > SHRT_MAX)
			err_free_exit(a, FILE_OVERFLOW);
		tmp = tmp->next;
	}
	if (tmp == target)
		return (return_short_value(len));
	len = 0;
	tmp = orig->prev;
	while (tmp != a->output)
	{
		if ((len -= tmp->size) < SHRT_MIN)
			err_free_exit(a, FILE_OVERFLOW);
		if (tmp == target)
			return (return_short_value(len));
		tmp = tmp->prev;
	}
	if ((len -= tmp->size) < SHRT_MIN)
		err_free_exit(a, FILE_OVERFLOW);
	return (return_short_value(len));
}

static unsigned short	label_null_short(t_asm *a, t_code *orig)
{
	ssize_t	len;
	t_code	*tail;

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
	return (return_short_value(len));
}

static unsigned short	label_address_short(t_asm *a, t_label *label,
											t_code *orig)
{
	t_code	*target;
	t_code	*tail;

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
	return (compute_len_short(a, orig, target));
}

unsigned short			convert_label_short(t_asm *a, t_code *op, char *str)
{
	t_label	*label;
	t_label	*tail;

	if (!(label = a->labels))
		asm_error(a, op->orig, str, UNKNOWN_LABEL);
	tail = label->prev;
	while (label != tail)
	{
		if (ft_strnequ(str + 1, label->name, ft_strlen(label->name) - 1))
			return (label_address_short(a, label, op));
		label = label->next;
	}
	if (ft_strnequ(str + 1, label->name, ft_strlen(label->name) - 1))
		return (label_address_short(a, label, op));
	asm_error(a, op->orig, str, UNKNOWN_LABEL);
	return (0);
}
