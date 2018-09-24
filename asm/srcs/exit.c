/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:51:33 by triou             #+#    #+#             */
/*   Updated: 2018/09/24 23:52:31 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void		print_usage_exit(void)
{
	ft_putstr(USAGE);
	exit(EXIT_FAILURE);
}

void		err_free_exit(t_asm *a, const char *err)
{
	if (!err)
		perror(NULL);
	else
		ft_putstr_fd(err, 2);
	if (a)
		free_input(a);
	exit(EXIT_FAILURE);
}

void		lex_error(t_asm *a, t_file *line)
{
	ft_putstr_fd("Lexical error at line ", 2);
	ft_putnbr_fd(line->n, 2);
	ft_putstr_fd(":\n", 2);
	ft_putstr_fd(line->line, 2);
	ft_putstr_fd("\n", 2);
	free_input(a);
	exit(EXIT_FAILURE);
}

void		header_error(t_asm *a, char *line)
{
	if (a)
		free_input(a);
	ft_putstr_fd(WRONG_HEADER, 2);
	free(line);
	exit(EXIT_FAILURE);
}

void		parser_error(t_asm *a, t_file *line)
{
	ft_putstr_fd("Parsing error at line ", 2);
	ft_putnbr_fd(line->n, 2);
	ft_putstr_fd(":\n", 2);
	ft_putstr_fd(line->line, 2);
	ft_putchar_fd('\n', 2);
	free_input(a);
	exit(EXIT_FAILURE);
}
