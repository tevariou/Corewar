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

static void	ft_buffer(char **buff, char *new)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(*buff, new)))
	{
		if (*buff)
			free(*buff);
		err_free_exit(NULL, NULL);
	}
	free(*buff);
	*buff = tmp;
}

static void	read_magic(int input)
{
	ssize_t			ret;
	unsigned int	buff;
	
	buff = 0;
	if ((ret = read(input, &buff, 4)) < 0)
		err_free_exit(NULL, NULL);
	reverse_byte(&buff, sizeof(buff)); 
	if (buff != COREWAR_EXEC_MAGIC)
		err_free_exit(NULL, WRONG_MAGIC);
}

static void	read_name(int input, int output)
{
	ssize_t			ret;
	char			buff[PROG_NAME_LENGTH];
	unsigned char	bin[SEPARATOR_LINE * 2];

	if ((ret = read(input, buff, PROG_NAME_LENGTH)) < 0)
		err_free_exit(NULL, NULL);
	ft_putstr_fd(NAME_CMD_STRING, output);
	ft_putstr_fd(" \"", output);
	ft_putstr_fd(buff, output);
	ft_putendl_fd("\"", output);
	if ((ret = read(input, bin, SEPARATOR_LINE * 2)) < 0)
		err_free_exit(NULL, NULL);
}

void	decompile_bin(char *file)
{
	int		input;
	int		output;
	char	*filename;
	char	*buff;

	buff = NULL;
	check_extension(file, EXT_COMP);
	if ((input = open(file, O_RDONLY)) < 0) 
		err_free_exit(NULL, NULL);
	read_magic(input);
	read_name(input, output);
	read_comment(input, output);
	read_content(input, output);
	if (close(input) < 0)
		err_free_exit(NULL, NULL);
	//filename = set_extension(NULL, file, EXT, EXT_COMP);
}
