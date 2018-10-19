/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:51:33 by triou             #+#    #+#             */
/*   Updated: 2018/10/19 18:27:18 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	output_error(t_asm *a, char *line, char *val)
{
	char	*p;
	char	*tmp;

	if (!(tmp = ft_strdup(val)))
		err_free_exit(a, NULL);
	ft_strclr(ft_strchr(tmp, ' '));
	ft_strclr(ft_strchr(tmp, '\t'));
	ft_strclr(ft_strchr(tmp, ','));
	ft_strclr(ft_strchr(tmp, ':'));
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

void		asm_warning(t_asm *a, t_file *line, char *str, const char *err)
{
	ft_putstr_fd("\033[1;35m", 2);
	ft_putstr_fd(err, 2);
	ft_putnbr_fd(line->n, 2);
	ft_putendl_fd(":", 2);
	output_error(a, line->line, str);
	ft_putstr_fd("\033[0m", 2);
}

void		champ_warning(unsigned int size)
{
	ft_putstr_fd("\033[1;35mWarning : Champion size is ", 2);
	ft_put_uint(size, 2);
	ft_putstr_fd(" bytes whereas specified maximum size is ", 2);
	ft_put_uint(CHAMP_MAX_SIZE, 2);
	ft_putendl_fd(" bytes\033[0m", 2);
}
