/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:43:31 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 17:39:07 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

void		ft_put_uint(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar('0' + nb % 10);
}

char		*set_extension(t_asm *a, char *file,
							const char *dest, const char *src)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(dest) - ft_strlen(src);
	if (!(ret = ft_memalloc((ft_strlen(file) + 1 + len) * sizeof(*ret))))
		err_free_exit(a, NULL);
	ft_strncpy(ret, file, ft_strlen(file) - ft_strlen(src));
	ft_strcat(ret, dest);
	return (ret);
}

void		reverse_bytes(void *n, size_t size)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	tmp;

	p = (unsigned char *)n;
	while (size && !(*p))
	{
		p++;
		size--;
	}
	i = 0;
	while (i < size / 2)
	{
		tmp = p[i];
		p[i] = p[size - i - 1];
		p[size - i - 1] = tmp;
		i++;
	}
}

static char	*get_line(t_asm *a, char *line, char **buff)
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

char		*get_quote(t_asm *a, int fd, size_t *n, char *line)
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
		&& (ret = get_next_line(fd, &buff)) > 0)
	{
		if (ret < 0)
			err_free_exit(a, NULL);
		line = get_line(a, line, &buff);
		if (!(*n += 1))
			header_error(a, line);
	}
	ft_strclr(line + ft_strlen(line) - 1);
	if (!ret)
		header_error(a, line);
	return (line);
}
