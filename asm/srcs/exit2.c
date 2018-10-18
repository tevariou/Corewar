/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:54:01 by triou             #+#    #+#             */
/*   Updated: 2018/10/12 20:19:27 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	decompile_error(char **out)
{
	ft_putendl_fd("ERROR", 2);
	if (out && *out)
		free(*out);
	exit(EXIT_FAILURE);
}

void	header_error(t_asm *a, char *line)
{
	free_all(a);
	ft_putendl_fd(WRONG_HEADER, 2);
	if (line)
		free(line);
	exit(EXIT_FAILURE);
}

void	print_usage_exit(void)
{
	ft_putendl_fd("Usage:\t./asm [-a] <sourcefile.s> | -d <binaryfile.cor>\n" \
	"Options:\t-a : Instead of creating a .cor file, outputs " \
	"a stripped and annotated version of the code to the standard output\n" \
	"\t\t-d : Translate a binary file into assembly", 2);
	exit(EXIT_FAILURE);
}

void	err_free_exit(t_asm *a, const char *err)
{
	if (!err)
		perror(NULL);
	else
		ft_putendl_fd(err, 2);
	if (a)
		free_all(a);
	exit(EXIT_FAILURE);
}
