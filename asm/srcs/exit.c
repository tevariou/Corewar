/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:51:33 by triou             #+#    #+#             */
/*   Updated: 2018/10/02 14:35:13 by triou            ###   ########.fr       */
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
	free_all(a);
	exit(EXIT_FAILURE);
}

void		asm_error(t_asm *a, t_file *line, char *err)
{
	ft_putstr_fd(err, 2);
	ft_putstr_fd(" at line ", 2);
	ft_putnbr_fd(line->n, 2);
	ft_putstr_fd(":\n", 2);
	ft_putendl_fd(line->line, 2);
	free_all(a);
	exit(EXIT_FAILURE);
}

void		header_error(t_asm *a, char *line)
{
	free_all(a);
	ft_putstr_fd(WRONG_HEADER, 2);
	free(line);
	exit(EXIT_FAILURE);
}

static void	output_error(char *line, char *val)
{
	char	*p;

	p = ft_strstr(line, val);
	write(2, line, p - line);
	ft_putstr_fd("\e[4m\033[1;31m", 2);
	ft_putstr_fd(val, 2);
	ft_putstr_fd("\033[0m\e[24m", 2);
	ft_putendl_fd(p + ft_strlen(val), 2);
}

void		parser_error(t_asm *a, t_file *line, char *val)
{
	ft_putstr_fd("Parser error at line ", 2);
	ft_putnbr_fd(line->n, 2);
	ft_putstr_fd(":\n", 2);
	output_error(line->line, val);
	free_all(a);
	exit(EXIT_FAILURE);
}

void		lex_error(t_asm *a, t_file *line, char *val)
{
	ft_putstr_fd("Lexical error at line ", 2);
	ft_putnbr_fd(line->n, 2);
	ft_putstr_fd(":\n", 2);
	output_error(line->line, val);
	free_all(a);
	exit(EXIT_FAILURE);
}

void		n_arg_error(t_asm *a, t_file *line)
{
	ft_putstr_fd("Wrong number of arguments at line ", 2);
	ft_putnbr_fd(line->n, 2);
	ft_putstr_fd(":\n", 2);
	ft_putstr_fd(line->line, 2);
	ft_putstr_fd("\n", 2);
	free_all(a);
	exit(EXIT_FAILURE);
}

void		label_error(t_asm *a, t_file *line, char *label)
{
	ft_putstr_fd("Unknown label found at line ", 2);
	ft_putnbr_fd(line->n, 2);
	ft_putstr_fd(":\n", 2);
	output_error(line->line, str);
	free_all(a);
	exit(EXIT_FAILURE);
}
