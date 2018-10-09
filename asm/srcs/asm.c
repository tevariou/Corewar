/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:02:20 by triou             #+#    #+#             */
/*   Updated: 2018/10/08 23:47:01 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
	t_asm	a;

	a.input = NULL;
	a.labels = NULL;
	a.output = NULL;
	if (ac <= 1 || ac > 3)
		print_usage_exit();
	a.option = set_option(ac, av);
	if (a.option == OPTION_D)
		decompile_bin(av[2]);
	else
	{
		compile_asm(&a, av[a.option + 1]);
		free_all(&a);
	}
	return (EXIT_SUCCESS);
}
