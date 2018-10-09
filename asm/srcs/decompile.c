/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:10:01 by triou             #+#    #+#             */
/*   Updated: 2018/10/08 22:47:56 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static void	ft_buffer(char **out, char *new)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(*out, new)))
		decompile_error(out);
	free(*out);
	*out = tmp;
}

static void	reverse_read(void *n, size_t size)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	tmp;

	p = (unsigned char *)n;
	i = 0;
	while (i < size / 2)
	{
		tmp = p[i];
		p[i] = p[size - i - 1];
		p[size - i - 1] = tmp;
		i++;
	}
}

static void	read_magic(int in)
{
	unsigned int	buff;
	
	if (read(in, &buff, sizeof(buff)) <= 0)
		decompile_error(NULL);
	reverse_read(&buff, sizeof(buff)); 
	if (buff != COREWAR_EXEC_MAGIC)
		decompile_error(NULL);
}

static void	read_name(int in, char **out)
{
	char			buff[PROG_NAME_LENGTH];
	unsigned char	bin[SEPARATOR_LINE * 2];

	if (read(in, buff, PROG_NAME_LENGTH) <= 0)
		decompile_error(out);
	ft_buffer(out, NAME_CMD_STRING);
	ft_buffer(out, " \"");
	ft_buffer(out, buff);
	ft_buffer(out, "\"\n");
	if (read(in, bin, SEPARATOR_LINE * 2) < 0)
		decompile_error(out);
}

static void	read_comment(int in, char **out)
{
	char			buff[COMMENT_LENGTH];
	unsigned char	bin[SEPARATOR_LINE];

	if (read(in, buff, COMMENT_LENGTH) <= 0)
		decompile_error(out);
	ft_buffer(out, COMMENT_CMD_STRING);
	ft_buffer(out, " \"");
	ft_buffer(out, buff);
	ft_buffer(out, "\"\n");
	if (read(in, bin, SEPARATOR_LINE) < 0)
		decompile_error(out);
}

static void	put_reg(int in, char **out, t_bool end)
{
	t_byte	buff;
	char	*n;

	if (read(in, &buff, sizeof(buff)) <= 0)
		decompile_error(out);
	ft_buffer(out, "r");
	if (!(n = ft_itoa(buff)))
		decompile_error(out);
	ft_buffer(out, n);
	free(n);
	if (!end)
		ft_buffer(out, ", ");
}

static void	put_ind(int in, char **out, t_bool end)
{
	short	buff;
	char	*n;

	if (read(in, &buff, sizeof(buff)) <= 0)
		decompile_error(out);
	reverse_read(&buff, sizeof(buff));
	if (!(n = ft_itoa(buff)))
		decompile_error(out);
	ft_buffer(out, n);
	free(n);
	if (!end)
		ft_buffer(out, ", ");
}

static void	put_dir(int in, char **out, t_bool end, t_bool len)
{
	int		buff;
	char	*n;

	ft_buffer(out, "%");
	if (len)
	{
		put_ind(in, out, end);
		return ;
	}
	if (read(in, &buff, sizeof(buff)) <= 0)
		decompile_error(out);
	reverse_read(&buff, sizeof(buff));
	if (!(n = ft_itoa(buff)))
		decompile_error(out);
	ft_buffer(out, n);
	free(n);
	if (!end)
		ft_buffer(out, ", ");
}

static t_bool	read_content(int in, char **out)
{
	t_byte	op;
	int		i;
	int		j;
	t_bool	end;
	ssize_t	ret;

	if ((ret = read(in, &op, sizeof(op))) < 0)
		decompile_error(out);
	if (!ret)
		return (TRUE);
	i = 0;
	while (g_op_tab[i].op_code)
	{
		if (g_op_tab[i].op_code == op)
		{
			ft_buffer(out, g_op_tab[i].name);
			ft_buffer(out, "\t");
			break ;
		}
		i++;
	}
	if (!g_op_tab[i].op_code)
		decompile_error(out);
	op = 0;
	if (g_op_tab[i].ocp && read(in, &op, sizeof(op)) <= 0)
		decompile_error(out);
	j = 0;
	end = FALSE;
	while (j < g_op_tab[i].n_args)
	{
		if (++j == g_op_tab[i].n_args)
			end = TRUE;
		if (op >> 6 == 1)
			put_reg(in, out, end);
		else if (op >> 6 == 2)
			put_dir(in, out, end, dir_len(g_op_tab[i].op_code));
		else if (op >> 6 == 3)
			put_ind(in, out, end);
		else
			put_dir(in, out, end, dir_len(g_op_tab[i].op_code));
		op <<= 2;
	}
	ft_buffer(out, "\n");
	return (FALSE);
}

void	decompile_bin(char *file)
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
	while (!read_content(fd, &out))
		;
	if (close(fd) < 0)
		decompile_error(&out);
	filename = set_extension(NULL, file, EXT, EXT_COMP);
	if ((fd = open(filename, O_RDWR | O_TRUNC | O_CREAT | O_APPEND, 0600)) < 0)
	{
		free(filename);
		decompile_error(&out);
	}
	ft_putstr_fd(out, fd);
	free(out);
	ft_putstr(DUMPING_D);
	ft_putendl(filename);
	free(filename);
	if (close(fd) < 0)
		decompile_error(NULL);
}
