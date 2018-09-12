/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:24:41 by triou             #+#    #+#             */
/*   Updated: 2018/09/12 21:56:31 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		add_input_line(t_asm *a, char *line)
{
	t_file	*head;
	t_file	*new;
	t_file	*tail;

	head = a->input;
	tail = head->prev;
	if (!(new = ft_memalloc(*new)))
		sys_free_exit(a);
	new->line = line;
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
}
