/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:55:12 by triou             #+#    #+#             */
/*   Updated: 2018/09/14 16:48:30 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h";
#include "asm.h"
#include "op.h"

static t_bool	check_extension(char *file)
{
	size_t	len;

	if ((len = ft_strlen(file)) <= 2 || !ft_strequ(file + len - 2, EXT))
	{
		ft_puterr(file);
		ft_puterr(":\n");
		ft_puterr(WRONG_EXT);
		return (FALSE);
	}
	return (TRUE);
}

static void		remove_whitespaces(t_asm *a, char **line)
{
	char	*tmp;

	tmp = *line;
	if (!(*line = ft_strtrim(*line)))
	{
		free(tmp);
		sys_free_exit(a);
	}
	free(tmp);
}

static void		record_file(t_asm *a, char *file)
{
	int		fd;
	int		ret;
	char	*line;

	a->input = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		sys_free_exit(a);
	line = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < -1)
			sys_free_exit(a);
		ft_strclr(ft_strchr(line, COMMENT_CHAR));
		remove_whitespaces(a, &line);
		if (*line)
			add_input_line(a, &line);
		else
			ft_strdel(&line);
	}
	if (close(fd) < 0)
		sys_free_exit(a);
}

static void		remove_header(t_asm *a)
{
	
}

t_bool			get_file(t_asm *a, char *file)
{
	int		fd;
	t_asm	a;

	if (!check_extension(file))
		return (FALSE);
	record_file(a, file);
	remove_header(a);
	return (TRUE);
}
