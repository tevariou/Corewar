/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 18:24:55 by triou             #+#    #+#             */
/*   Updated: 2018/10/03 23:50:29 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

static void		record_prog_name(t_asm *a, char *line, char *s)
{
	size_t	len;
	
	if ((len = ft_strchr(s, '"') - s) > PROG_NAME_LENGTH)
	{
		free(line);
		err_free_exit(a, NAME_TOO_LONG);
	}
	ft_bzero(a->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_strncpy(a->header.prog_name, s, len);
	s = ft_strchr(s, '"') + 1;
	while (ft_isspace(*s))
		s++;
	if (*s && *s != '#')
		header_error(a, line);
	free(line);
}

static void		get_quote_name(t_asm *a, int fd, size_t *n, char *line)
{
	char	*s;
	char	*buff;
	char	*tmp;
	int		ret;

	s = line;
	while (ft_isspace(*s))
		s++;
	if (*s == '"')
		s++;
	else
		header_error(a, line);
	buff = NULL;
	while (!ft_strchr(ft_strchr(line, '"') + 1, '"') && (ret = get_next_line(fd, &buff)) > 0)
	{
		if (ret < 0)
			err_free_exit(a, NULL);
		tmp = line;
		line = ft_strjoin(line, buff);
		free(tmp);
		ft_strdel(&buff);
		if (!line)
			err_free_exit(a, NULL);
		tmp = line;
		line = ft_strjoin(line, "\n");
		free(tmp);
		if (!line)
			err_free_exit(a, NULL);
		if (!(*n += 1))
			err_free_exit(a, FILE_OVERFLOW);
	}
	ft_strclr(line + ft_strlen(line) - 1);
	if (!ret)
		header_error(a, line);
	record_prog_name(a, line, ft_strchr(line, '"') + 1);
}

void		get_name(t_asm *a, int fd, size_t *n)
{
	int		ret;
	char	*line;
	char	*tmp;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < 0)
			err_free_exit(a, NULL);
		tmp = line;
		while (ft_isspace(*tmp))
			tmp++;
		if (!(*n += 1))
			err_free_exit(a, FILE_OVERFLOW);
		if (*tmp && *tmp != COMMENT_CHAR)
			break ;	
		ft_strdel(&line);
	}
	if (!ft_strnequ(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		header_error(a, line);
	tmp = line;
	line = ft_strjoin(line + ft_strlen(NAME_CMD_STRING), "\n");
	free(tmp);	
	if (!line)
		err_free_exit(a, NULL);
	get_quote_name(a, fd, n, line);
}
