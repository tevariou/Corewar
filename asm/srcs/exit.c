/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:51:33 by triou             #+#    #+#             */
/*   Updated: 2018/09/12 21:16:48 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void		ft_puterr(const char *err)
{
	write(2, err, ft_strlen(err));
}

void		print_usage_exit(void)
{
	ft_puterr(USAGE);
	exit(EXIT_FAILURE);
}

static void	free_input(t_asm *a)
{
	t_file	*head;
	t_file	*tail;
	t_file	*tmp;

	if (!(head = a->input))
		return ;
	tail = a->input->prev;
	while (head != tail)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
	a->input = NULL;
}

void		sys_free_exit(t_asm *a)
{
	perror(NULL);
	free_input(a);
	exit(EXIT_FAILURE);
}
