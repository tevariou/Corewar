/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:43:31 by triou             #+#    #+#             */
/*   Updated: 2018/10/19 14:45:33 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>

static char			*get_line(t_asm *a, char *line, char **buff)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(line, *buff)))
	{
		ft_strdel(buff);
		header_error(a, line);
	}
	free(line);
	line = tmp;
	ft_strdel(buff);
	if (!(tmp = ft_strjoin(line, "\n")))
		header_error(a, line);
	free(line);
	return (tmp);
}

char				*get_quote(t_asm *a, int fd, unsigned short *n, char *line)
{
	char	*s;
	char	*buff;
	int		ret;

	s = skip_space(line);
	if (*s == '"')
		s++;
	else
		header_error(a, line);
	buff = NULL;
	ret = -1;
	while (!ft_strchr(ft_strchr(line, '"') + 1, '"')
		&& (ret = get_next_line(fd, &buff)))
	{
		if (ret < 0)
			header_error(a, line);
		line = get_line(a, line, &buff);
		if (!(*n += 1))
			header_error(a, line);
	}
	ft_strclr(line + ft_strlen(line) - 1);
	if (!ret)
		header_error(a, line);
	return (line);
}

char				*start_read(t_asm *a, int fd, char **line,
		unsigned short *n)
{
	int		ret;
	char	*tmp;

	tmp = NULL;
	*line = NULL;
	while ((ret = get_next_line(fd, line)))
	{
		if (ret < 0)
			header_error(a, *line);
		tmp = skip_space(*line);
		if (!(*n += 1))
			header_error(a, *line);
		if (*tmp && *tmp != COMMENT_CHAR)
			break ;
		ft_strdel(line);
	}
	return (tmp);
}
