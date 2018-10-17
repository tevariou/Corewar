/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:47:43 by triou             #+#    #+#             */
/*   Updated: 2018/10/12 20:08:09 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static void	get_prog_size(t_asm *a)
{
	t_code			*list;
	t_code			*tail;
	unsigned int	size;

	list = a->output;
	tail = list->prev;
	size = 0;
	while (list != tail)
	{
		size += list->size;
		list = list->next;
	}
	size += list->size;
	if (size > CHAMP_MAX_SIZE)
		champ_warning(size);
	reverse_bytes(&size, sizeof(size));
	a->header.prog_size = size;
}

static void	write_header(t_asm *a, int fd)
{
	char	line[SEPARATOR_LINE];

	ft_bzero(line, SEPARATOR_LINE);
	a->header.magic = COREWAR_EXEC_MAGIC;
	reverse_bytes(&(a->header.magic), sizeof(a->header.magic));
	get_prog_size(a);
	write(fd, &(a->header.magic), sizeof(a->header.magic));
	write(fd, a->header.prog_name, PROG_NAME_LENGTH);
	write(fd, line, SEPARATOR_LINE);
	write(fd, &(a->header.prog_size), sizeof(a->header.prog_size));
	write(fd, a->header.comment, COMMENT_LENGTH);
	write(fd, line, SEPARATOR_LINE);
}

static void	put_code(t_code *list, int fd)
{
	int	i;

	write(fd, &(list->op_code), sizeof(list->op_code));
	if (list->ocp)
		write(fd, &(list->ocp), sizeof(list->ocp));
	i = 0;
	while (i < 3 && list->args_type[i])
	{
		if (list->args_type[i] == T_DIR && !dir_len(list->op_code))
			write(fd, &(list->args[i].u32), sizeof(list->args[i].u32));
		else if (list->args_type[i] == T_REG)
			write(fd, &(list->args[i].u8), sizeof(list->args[i].u8));
		else
			write(fd, &(list->args[i].u16), sizeof(list->args[i].u16));
		i++;
	}
}

static void	write_content(t_asm *a, int fd)
{
	t_code	*list;
	t_code	*tail;

	list = a->output;
	tail = list->prev;
	while (list != tail)
	{
		put_code(list, fd);
		list = list->next;
	}
	put_code(list, fd);
}

void		write_bytecode(t_asm *a, char *file)
{
	int		fd;
	char	*filename;

	filename = set_extension(a, file, EXT_COMP, EXT);
	if ((fd = open(filename, O_RDWR | O_TRUNC | O_CREAT | O_APPEND, 0600)) < 0)
	{
		free(filename);
		err_free_exit(a, NULL);
	}
	write_header(a, fd);
	write_content(a, fd);
	ft_putstr(WRITING_FILE);
	ft_putendl(filename);
	free(filename);
	if (close(fd) < 0)
		err_free_exit(a, NULL);
}
