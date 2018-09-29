/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:55:12 by triou             #+#    #+#             */
/*   Updated: 2018/09/29 16:25:43 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "asm.h"

static void		check_extension(char *file)
{
	size_t	len;

	if ((len = ft_strlen(file)) <= 2 || !ft_strequ(file + len - 2, EXT))
		err_free_exit(NULL, WRONG_EXT);
}

static void		remove_whitespaces(t_asm *a, char **line)
{
	char	*tmp;

	tmp = *line;
	if (!(*line = ft_strtrim(*line)))
	{
		free(tmp);
		err_free_exit(a, NULL);
	}
	free(tmp);
}

static void		record_file(t_asm *a, int fd)
{
	int		ret;
	char	*line;
	size_t	n;

	line = NULL;
	n = 1;
	get_name(a, fd, n);
	get_comment(a, fd, n);
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

	check_extension(file);
	if ((fd = open(file, O_RDONLY)) < 0)
		err_free_exit(a, NULL);
	record_file(a, fd);
	if (close(fd) < 0)
		err_free_exit(a, NULL);
}
