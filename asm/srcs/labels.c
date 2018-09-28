/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:57:14 by triou             #+#    #+#             */
/*   Updated: 2018/09/28 21:43:34 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	add_label(t_asm *a)
{
	t_lab	*l;
	t_lab	*new;

	if (!(new = ft_memalloc(sizeof(*new))))
		err_free_exit(a, NULL);
	if (!(l = a->labels))
	{
		
	}
}

static void	assign_labels(t_asm *a, t_file *list)
{
	t_file	*tmp;
	t_file	*tail;
	size_t	n;

	tmp = list;
	tail = tmp->prev;
	while (tmp != tail && !(tmp->n_args))
		tmp = tmp->next;
	n = (tmp == tail && !(tmp->n_args)) ? 0 : tmp->n;
	while (list != tail && list->n_args)
	{
		add_label(a, );	
		list = list->next;
	}
	add_label(a, list);
}

void		get_labels(t_asm *a)
{
	t_file	*list;
	t_file	*tail;

	a->labels = NULL;
	list = a->input;
	tail = list->prev;
	tmp = NULL;
	while (list != tail)
		list = assign_labels(a, list);
	assign_labels(list);
}
