/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:55:12 by triou             #+#    #+#             */
/*   Updated: 2018/10/08 23:41:08 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "asm.h"

void		check_extension(char *file, const char *ext)
{
	size_t	len;

	if ((len = ft_strlen(file)) <= ft_strlen(ext)
		|| !ft_strequ(file + len - ft_strlen(ext), ext))
		err_free_exit(NULL, WRONG_EXT);
}

static void		remove_whitespaces(t_asm *a, char **line)
{
	char	*tmp;

	if (!(tmp = ft_strtrim(*line)))
	{
		free(*line);
		err_free_exit(a, NULL);
	}
	*line = tmp;
}

static void		record_file(t_asm *a, int fd)
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
