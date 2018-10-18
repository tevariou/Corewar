/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:59:00 by triou             #+#    #+#             */
/*   Updated: 2018/09/13 00:28:04 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

static int	read_data(char *data, const int fd, char **line)
{
	char	*tmp;
	size_t	len;

	if (fd < 0 || !line)
		return (-1);
	if ((tmp = ft_strchr(data, '\n')))
	{
		len = ft_strlen(data) - (tmp - data + 1);
		if (!(*line = ft_strsub(data, 0, tmp - data)))
			return (-1);
		ft_memmove(data, tmp + 1, len);
		ft_strclr(data + len);
		return (1);
	}
	*line = ft_strdup(data);
	ft_strclr(data);
	return ((*line) ? 0 : -1);
}

static int	save_data(int ret, char **line, char *data)
{
	char	*tmp;

	if (ret < 0)
	{
		ft_strdel(line);
		return (-1);
	}
	else if (!ret && !(**line))
	{
		ft_strdel(line);
		return (0);
	}
	else if (!(tmp = ft_strchr(*line, '\n')) && !ret)
		return (-1);
	ft_strcpy(data, tmp + 1);
	ft_strclr(tmp);
	tmp = *line;
	*line = ft_strdup(*line);
	free(tmp);
	return ((*line) ? 1 : -1);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static char		buff[BUFF_SIZE + 1];
	char			*tmp;

	if ((ret = read_data(buff, fd, line)))
		return (ret);
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
	ft_strclr(buff);
	return (save_data(ret, line, buff));
}
