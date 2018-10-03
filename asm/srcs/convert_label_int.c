/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_label_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:35:02 by triou             #+#    #+#             */
/*   Updated: 2018/10/03 23:25:04 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "asm.h"

static unsigned int	compute_len_int(t_asm *a, t_code *orig, t_code *target)
{
	long			len;
	unsigned int	ret;
	t_code			*tmp;	
	t_code			*tail;

	len = 0;
	tmp = orig;
	tail = a->output->prev;
	while (tmp != tail)
	{
		if (tmp == target)
		{
			ret = (unsigned int)len;
			reverse_bytes(&ret, sizeof(ret));
			return (ret);
		}
		if ((len += tmp->size) > INT_MAX)
			err_free_exit(a, FILE_OVERFLOW);
		tmp = tmp->next;
	}
	if (tmp == target)
	{
		ret = (unsigned int)len;
		reverse_bytes(&ret, sizeof(ret));
		return (ret);
	}
	len = 0;
	tmp = orig;
	tail = a->output;
	while (tmp != tail)
	{
		if (tmp == target)
		{
			ret = (unsigned int)len;
			reverse_bytes(&ret, sizeof(ret));
			return (ret);
		}
		if ((len -= tmp->size) < INT_MIN)
			err_free_exit(a, FILE_OVERFLOW);
		tmp = tmp->prev;
	}
	if (tmp == target)
	{
		ret = (unsigned int)len;
		reverse_bytes(&ret, sizeof(ret));
		return (ret);
	}
	return (0);
}

static unsigned int label_null_int(t_asm *a, t_code *orig)
{
	long			len;
	unsigned int	ret;
	t_code			*tail;

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
	ret = (unsigned int)len;
	reverse_bytes(&ret, sizeof(ret));
	return (ret);
}

static unsigned int	label_address_int(t_asm *a, t_label *label, t_code *orig, char *str)
{
	t_code			*target;
	t_code			*tail;

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
	if (target->orig == label->target)
		return (compute_len_int(a, orig, target));
	label_error(a, orig->orig, str);
	return (0);
}

unsigned int			convert_label_int(t_asm *a, t_code *op, char *str)
{
	t_label	*label;
	t_label	*tail;

	if(!(label = a->labels))
		label_error(a, op->orig, str);
	tail = label->prev;
	while (label != tail)
	{
		if (ft_strnequ(str + 1, label->name, ft_strlen(label->name) - 1))
			return (label_address_int(a, label, op, str));
		label = label->next;	
	}
	if (ft_strnequ(str + 1, label->name, ft_strlen(label->name) - 1))
		return (label_address_int(a, label, op, str));
	label_error(a, op->orig, str);
	return (0);
}
