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

void		lex_error(t_asm *a, t_file *line)
{
	ft_puterr("Lexical error at line ");
	ft_putnbr(line->n);
	ft_putstr(":\n\t");
	ft_putstr(line->line);
	ft_putchar('\n');
	free_input(a);
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
