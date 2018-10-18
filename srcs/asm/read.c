/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:55:12 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 20:56:18 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "asm.h"
#include "libft.h"

static void	add_input_line(t_asm *a, char *line, unsigned short n)
{
	t_file	*head;
	t_file	*new;
	t_file	*tail;

	if (!(new = ft_memalloc(sizeof(*new))))
		err_free_exit(a, NULL);
	new->line = line;
	new->n = n;
	new->tokens = NULL;
	if (!(head = a->input))
	{
		new->prev = new;
		new->next = new;
		a->input = new;
		return ;
	}
	tail = head->prev;
	tail->next = new;
	new->prev = tail;
	new->next = head;
	head->prev = new;
}

static void	remove_whitespaces(t_asm *a, char **line)
{
	char	*tmp;

	if (!(tmp = ft_strtrim(*line)))
	{
		free(*line);
		err_free_exit(a, NULL);
	}
	free(*line);
	*line = tmp;
}

static void	record_file(t_asm *a, int fd, unsigned short n)
{
	int				ret;
	char			*line;

	line = NULL;
	get_header(a, fd, &n, false);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < 0 && !line)
			err_free_exit(a, NULL);
		ft_strclr(ft_strchr(line, COMMENT_CHAR));
		ft_strclr(ft_strchr(line, ';'));
		remove_whitespaces(a, &line);
		if (*line && ret > 0)
			add_input_line(a, line, n);
		else if (*line)
		{
			free(line);
			err_free_exit(a, NO_NEWLINE);
		}
		else
			free(line);
		line = NULL;
		if (!(++n))
			err_free_exit(a, FILE_OVERFLOW);
	}
}

void		get_file(t_asm *a, char *file)
{
	int				fd;

	check_extension(file, EXT);
	if ((fd = open(file, O_RDONLY)) < 0)
		err_free_exit(a, NULL);
	record_file(a, fd, 1);
	if (close(fd) < 0)
		err_free_exit(a, NULL);
}
