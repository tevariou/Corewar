/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:57:11 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/28 15:20:02 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "mars.h"

void	ft_info_processus(t_processus *process)
{
	unsigned	i;

	i = 0;
	if (!process)
		ft_exit(NULL, "no process");
	printf("\nprocessus -> %s\n", process->name);
	printf("pc -> %d\n", process->pc);
	printf("player -> %d\n", process->player);
	while (i < REG_NUMBER)
	{
		printf("register %2d = %2d || ",i , ft_get_register(process, i));
		if (!((i + 1) % (REG_NUMBER / 4)))
			printf("\n");
		i++;
	}
			printf("\n");
}
