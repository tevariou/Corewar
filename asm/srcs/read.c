/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:55:12 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 17:37:49 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "asm.h"

static void	add_input_line(t_asm *a, char *line, size_t n)
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

static void	record_file(t_asm *a, int fd)
{
	int		ret;
	char	*line;
	size_t	n;

	line = NULL;
	n = 1;
	get_name(a, fd, &n);
	get_comment(a, fd, &n);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < 0)
			err_free_exit(a, NULL);
		ft_strclr(ft_strchr(line, COMMENT_CHAR));
		remove_whitespaces(a, &line);
		if (*line)
			add_input_line(a, line, n);
		else
			free(line);
		line = NULL;
		if (!(++n))
			err_free_exit(a, FILE_OVERFLOW);
	}
}

void		get_file(t_asm *a, char *file)
{
	int		fd;

	check_extension(file, EXT);
	if ((fd = open(file, O_RDONLY)) < 0)
		err_free_exit(a, NULL);
	record_file(a, fd);
	if (close(fd) < 0)
		err_free_exit(a, NULL);
}
