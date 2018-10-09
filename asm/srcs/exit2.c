/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:54:01 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 21:37:21 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>
#include <stdlib.h>

void	print_usage_exit(void)
{
	ft_putstr_fd("Usage:\t./asm [-a] <sourcefile.s>", 2);
	ft_putstr_fd(" | -d <binaryfile.cor>\n", 2);
	ft_putstr_fd("Options:\t-a : Instead of creating a .cor file, outputs ", 2);
	ft_putstr_fd("a stripped and annotated version of the code ", 2);
	ft_putstr_fd("to the standard output\n", 2);
	ft_putendl_fd("\t\t-d : Translate a binary file into assembly", 2);
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
