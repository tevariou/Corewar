/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompile_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:48:28 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 20:00:31 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void		read_magic(int in)
{
	unsigned int	buff;

	if (read(in, &buff, sizeof(buff)) <= 0)
		decompile_error(NULL);
	reverse_bytes(&buff, sizeof(buff));
	if (buff != COREWAR_EXEC_MAGIC)
		decompile_error(NULL);
}

void		read_name(int in, char **out)
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

void		read_comment(int in, char **out)
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

static void	put_values(t_byte op, int i, int in, char **out)
{
	int		j;
	bool	end;

	j = 0;
	end = false;
	while (j < g_op_tab[i].n_args)
	{
		if (++j == g_op_tab[i].n_args)
			end = true;
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
}

void		read_content(int in, char **out)
{
	t_byte	op;
	int		i;
	ssize_t	ret;

	if ((ret = read(in, &op, sizeof(op))) < 0)
		decompile_error(out);
	if (!ret)
		return ;
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
	op = 0;
	if (!g_op_tab[i].op_code
		|| (g_op_tab[i].ocp && read(in, &op, sizeof(op)) <= 0))
		decompile_error(out);
	put_values(op, i, in, out);
	read_content(in, out);
}
