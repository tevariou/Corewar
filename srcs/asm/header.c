/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 18:24:35 by triou             #+#    #+#             */
/*   Updated: 2018/10/10 12:07:15 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>

static void	record_comment(t_asm *a, char *line, char *s)
{
	size_t	len;

	if ((len = ft_strchr(s, '"') - s) > COMMENT_LENGTH)
	{
		free(line);
		err_free_exit(a, COMMENT_TOO_LONG);
	}
	ft_bzero(a->header.comment, COMMENT_LENGTH + 1);
	ft_strncpy(a->header.comment, s, len);
	s = ft_strchr(s, '"') + 1;
	while (ft_isspace(*s))
		s++;
	if (*s && *s != COMMENT_CHAR)
		header_error(a, line);
	free(line);
}

static void	get_comment(t_asm *a, int fd, unsigned short *n)
{
	char	*line;
	char	*tmp;

	if (!(tmp = start_read(a, fd, &line, n)))
		err_free_exit(a, WRONG_HEADER);
	if (!ft_strnequ(tmp, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING))
		|| !(tmp = ft_strjoin(tmp + ft_strlen(COMMENT_CMD_STRING), "\n")))
		header_error(a, line);
	free(line);
	line = get_quote(a, fd, n, tmp);
	record_comment(a, line, ft_strchr(line, '"') + 1);
}

static void	record_name(t_asm *a, char *line, char *s)
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
	if (*s && *s != COMMENT_CHAR)
		header_error(a, line);
	free(line);
}

void		get_header(t_asm *a, int fd, unsigned short *n, bool flag)
{
	char	*line;
	char	*tmp;

	if (!(tmp = start_read(a, fd, &line, n)))
		err_free_exit(a, WRONG_HEADER);
	if (!flag
		&& ft_strnequ(tmp, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		if (!(tmp = ft_strjoin(tmp + ft_strlen(COMMENT_CMD_STRING), "\n")))
			header_error(a, line);
		free(line);
		line = get_quote(a, fd, n, tmp);
		record_comment(a, line, ft_strchr(line, '"') + 1);
		return (get_header(a, fd, n, true));
	}
	if (!ft_strnequ(tmp, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))
		|| !(tmp = ft_strjoin(tmp + ft_strlen(NAME_CMD_STRING), "\n")))
		header_error(a, line);
	free(line);
	line = get_quote(a, fd, n, tmp);
	record_name(a, line, ft_strchr(line, '"') + 1);
	if (!flag)
		get_comment(a, fd, n);
}
