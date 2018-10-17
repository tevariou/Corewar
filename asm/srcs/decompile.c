/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:10:01 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 20:01:34 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	write_output(int fd, char *out, char *filename)
{
	ft_putstr_fd(out, fd);
	free(out);
	ft_putstr(DUMPING_D);
	ft_putendl(filename);
	free(filename);
}

void		decompile_bin(char *file)
{
	int		fd;
	char	*filename;
	char	*out;

	out = NULL;
	check_extension(file, EXT_COMP);
	if ((fd = open(file, O_RDONLY)) < 0)
		decompile_error(NULL);
	read_magic(fd);
	read_name(fd, &out);
	read_comment(fd, &out);
	ft_buffer(&out, "\n");
	read_content(fd, &out);
	if (close(fd) < 0)
		decompile_error(&out);
	filename = set_extension(NULL, file, EXT, EXT_COMP);
	if ((fd = open(filename, O_RDWR | O_TRUNC | O_CREAT | O_APPEND, 0600)) < 0)
	{
		free(filename);
		decompile_error(&out);
	}
	write_output(fd, out, filename);
	if (close(fd) < 0)
		decompile_error(NULL);
}
