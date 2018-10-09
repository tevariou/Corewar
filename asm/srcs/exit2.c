/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:54:01 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 18:56:21 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>
#include <stdlib.h>

void		print_usage_exit(void)
{
	ft_putendl_fd(USAGE, 2);
	exit(EXIT_FAILURE);
}

void		err_free_exit(t_asm *a, const char *err)
{
	if (!err)
		perror(NULL);
	else
		ft_putendl_fd(err, 2);
	if (a)
		free_all(a);
	exit(EXIT_FAILURE);
}
