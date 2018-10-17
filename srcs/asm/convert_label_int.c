/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_label_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:35:02 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 20:47:28 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "asm.h"
#include "libft.h"

static unsigned int	return_int_value(long len)
{
	unsigned int	ret;

	ret = (unsigned int)len;
	reverse_bytes(&ret, sizeof(ret));
	return (ret);
}

static unsigned int	compute_len_int(t_asm *a, t_code *orig, t_code *target)
{
	long	len;
	t_code	*tmp;

	len = 0;
	tmp = orig;
	while (tmp != a->output->prev && tmp != target)
	{
		if ((len += tmp->size) > INT_MAX)
			err_free_exit(a, FILE_OVERFLOW);
		tmp = tmp->next;
	}
	if (tmp == target)
		return (return_int_value(len));
	len = 0;
	tmp = orig->prev;
	while (tmp != a->output && (len - tmp->size) >= (long)INT_MIN)
	{
		len -= tmp->size;
		if (tmp == target)
			return (return_int_value(len));
		tmp = tmp->prev;
	}
	if ((len -= tmp->size) < INT_MIN)
		err_free_exit(a, FILE_OVERFLOW);
	return (return_int_value(len));
}

static unsigned int	label_null_int(t_asm *a, t_code *orig)
{
	long	len;
	t_code	*tail;

	len = 0;
	tail = a->output->prev;
	while (orig != tail)
	{
		if ((len += orig->size) > INT_MAX)
			err_free_exit(a, FILE_OVERFLOW);
		orig = orig->next;
	}
	if ((len += orig->size) > INT_MAX)
		err_free_exit(a, FILE_OVERFLOW);
	return (return_int_value(len));
}

static unsigned int	label_address_int(t_asm *a, t_label *label, t_code *orig)
{
	t_code	*target;
	t_code	*tail;

	if (!(label->target))
		return (label_null_int(a, orig));
	target = a->output;
	tail = target->prev;
	while (target != tail)
	{
		if (target->orig == label->target)
			return (compute_len_int(a, orig, target));
		target = target->next;
	}
	return (compute_len_int(a, orig, target));
}

unsigned int		convert_label_int(t_asm *a, t_code *op, char *str)
{
	t_label	*label;
	t_label	*tail;

	if (!(label = a->labels))
		asm_error(a, op->orig, str, UNKNOWN_LABEL);
	tail = label->prev;
	while (label != tail)
	{
		if (ft_strequ(str + 1, label->name))
			return (label_address_int(a, label, op));
		label = label->next;
	}
	if (ft_strequ(str + 1, label->name))
		return (label_address_int(a, label, op));
	asm_error(a, op->orig, str, UNKNOWN_LABEL);
	return (0);
}
