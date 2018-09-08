/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:59:00 by triou             #+#    #+#             */
/*   Updated: 2018/09/09 00:44:48 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_save_data(char *data, char **line)
{
	char	*tmp;

	ft_strcpy(data, ft_strchr(*line, '\n') + 1);
	tmp = *line;
	ft_strclr(ft_strchr(*line, '\n'));
	*line = ft_strdup(*line);
	free(tmp);
	return ((*line) ? 1 : -1);
}

static int	ft_read_data(char *data, const int fd, char **line)
{
	char	*str;
	size_t	size;
	size_t	len;

	if (fd < 0 || !line)
		return (-1);
	if ((str = ft_strchr(data, '\n')))
	{
		size = str - data;
		len = ft_strlen(data) - (size + 1);
		if (!(*line = ft_strsub(data, 0, size)))
			return (-1);
		ft_memmove(data, data + size + 1, len);
		ft_strclr(data + len);
		return (1);
	}
	*line = ft_strdup(data);
	ft_strclr(data);
	return ((*line) ? 0 : -1);
}

static int	ft_output(int ret, char **line, char *data)
{
	if (ret < 0)
		return (-1);
	else if (!ret && !(**line))
	{
		ft_strdel(line);
		return (0);
	}
	else if (!ret && !ft_strchr(*line, '\n'))
		return (1);
	return (ft_save_data(data, line));
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static char		data[BUFF_SIZE + 1];
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	if ((ret = ft_read_data(data, fd, line)))
		return (ret);
	buff[0] = '\0';
	while (!ft_strchr(buff, '\n')
		&& (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
		if (!(*line))
			return (-1);
	}
	return (ft_output(ret, line, data));
}
