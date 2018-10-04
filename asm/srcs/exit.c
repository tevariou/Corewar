/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:51:33 by triou             #+#    #+#             */
/*   Updated: 2018/10/03 19:48:14 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void		print_usage_exit(void)
{
	ft_putendl_fd(USAGE, 2);
	exit(EXIT_FAILURE);
}

void		err_free_exit(t_asm *a, const char *err)
{
	if (!err)
		perror(NULL);
	else
		ft_putendl_fd(err, 2);
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

static void	output_error(t_asm *a, char *line, char *val)
{
	char	*p;
	char	*tmp;

	if (!(tmp = ft_strdup(val)))
		err_free_exit(a, NULL);
	ft_strclr(ft_strchr(tmp, ' '));
	ft_strclr(ft_strchr(tmp, ','));
	p = ft_strstr(line, val);
	write(2, line, p - line);
	ft_putstr_fd("\e[4m\033[1;31m", 2);
	ft_putstr_fd(tmp, 2);
	ft_putstr_fd("\033[0m\e[24m", 2);
	ft_putendl_fd(p + ft_strlen(tmp), 2);
	free(tmp);
}

void		parser_error(t_asm *a, t_file *line, const char *err)
{
	ft_putstr_fd(err, 2);
	ft_putnbr_fd(line->n, 2);
	ft_putendl_fd(":", 2);
	ft_putendl_fd(line->line, 2);
	free_all(a);
	exit(EXIT_FAILURE);
}

void		asm_error(t_asm *a, t_file *line, char *str, const char *err)
{
	ft_putstr_fd(err, 2);
	ft_putnbr_fd(line->n, 2);
	ft_putendl_fd(":", 2);
	output_error(a, line->line, str);
	free_all(a);
	exit(EXIT_FAILURE);
}
