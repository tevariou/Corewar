/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:24:41 by triou             #+#    #+#             */
/*   Updated: 2018/09/15 13:42:00 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>

void		add_input_line(t_asm *a, char **line, size_t n)
{
	t_file	*head;
	t_file	*new;
	t_file	*tail;

	head = a->input;
	tail = head->prev;
	if (!(new = ft_memalloc(*new)))
		err_free_exit(a, NULL);
	new->line = *line;
	new->n = n;
	if (!(head))
	{
		new->prev = a->input;
		new->next = a->input;
		a->input = new;
		return ;
	}
	tail->next = new;
	new->prev = tail;
	new->next = head;
	head->prev = new;
	*line = NULL;
}
