/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:57:14 by triou             #+#    #+#             */
/*   Updated: 2018/09/28 18:49:47 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	get_labels(t_asm *a)
{
	t_file	*list;
	t_file	*tail;
	char	**tmp;

	list = a->input;
	tail = list->prev;
	tmp = NULL;
	while (list != tail)
	{
		if (!(line->args))
		{
			
		}
		list = list->next;
	}
}
