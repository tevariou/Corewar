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

void		get_comment(t_asm *a, int fd, unsigned short *n)
{
	int		ret;
	char	*line;
	char	*tmp;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < 0)
			err_free_exit(a, NULL);
		tmp = skip_space(line);
		if (!(*n += 1))
			header_error(a, line);
		if (*tmp && *tmp != COMMENT_CHAR)
			break ;
		ft_strdel(&line);
	}
	if (!ft_strnequ(tmp, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		header_error(a, line);
	if (!(tmp = ft_strjoin(tmp + ft_strlen(COMMENT_CMD_STRING), "\n")))
	{
		free(line);
		err_free_exit(a, NULL);
	}
	free(line);
	line = get_quote(a, fd, n, tmp);
	record_comment(a, line, ft_strchr(line, '"') + 1);
}
