/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:02:20 by triou             #+#    #+#             */
/*   Updated: 2018/09/12 20:25:42 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

int	main(int ac, char **av)
{
	int		i;
	t_asm	a;

	if (ac <= 1 || ac > 3)
		print_usage_exit();
	a.option = set_option(av);
	compile_file(&a, av[a.option + 1]);
	return (EXIT_SUCCESS);
}