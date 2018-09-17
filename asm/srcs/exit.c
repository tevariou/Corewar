/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:51:33 by triou             #+#    #+#             */
/*   Updated: 2018/09/17 21:24:18 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void		ft_puterr(const char *err)
{
	if (err)
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

void		err_free_exit(t_asm *a, const char *err)
{
	if (!err)
		perror(NULL);
	else
		ft_puterr(err);
	if (a)
		free_input(a);
	exit(EXIT_FAILURE);
}

void		parse_error(t_asm *a, char *line, size_t n)
{
	if (a)
		free_input(a);
	ft_puterr("Error at line ");
	ft_putnbr(n);
	ft_putstr(":\n\t");
	ft_putstr(line);
	ft_putchar('\n');
	free(line);
	exit(EXIT_FAILURE);
}

void		header_error(t_asm *a, char *line)
{
	if (a)
		free_input(a);
	ft_putstr(WRONG_HEADER);
	free(line);
	exit(EXIT_FAILURE);
}
