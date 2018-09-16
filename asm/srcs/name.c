#include "libft.h"
#include "asm.h"
#include <stdlib.h>

static void		record_prog_name(t_asm *a, char *line, char *s, size_t *n)
{
	size_t	len;
	
	if ((len = ft_strchr(s, '"') - s) > PROG_NAME_LENGTH)
	{
		free(line);
		err_free_exit(a, NAME_TOO_LONG);
	}
	ft_bzero(a->header->prog_name, PROG_NAME_LENGTH + 1);
	ft_strncpy(a->header->prog_name, s, len);
	s = ft_strchr(s, '"');
	while (ft_isspace(*s))
		s++;
	if (*s && *s != '#')
		parse_error(a, line, *n);
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
		parse_error(a, line, *n);
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
		if (!(++(*n)))
			err_free_exit(a, FILE_OVERFLOW);
	}
	if (!ret)
		parse_error(a, line, *n);
	record_prog_name(a, line, ft_strchr(line, '"') + 1, n);
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
		if (*tmp && *tmp != COMMENT_CHAR)
			break ;	
		ft_strdel(&line);
		if (!(++(*n)))
			err_free_exit(a, FILE_OVERFLOW);
	}
	if (!ft_strnequ(line, str, ft_strlen(NAME_CMD_STRING)))
		parse_error(a, line, *n);
	tmp = line;
	line = ft_strdup(line + ft_strlen(NAME_CMD_STRING));
	free(tmp);	
	if (!line)
		err_free_exit(a, NULL);
	get_quote_name(a, fd, n, line);
}
