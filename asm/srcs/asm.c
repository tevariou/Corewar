/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:02:20 by triou             #+#    #+#             */
/*   Updated: 2018/09/17 21:31:57 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

void	print_file(t_file *input)
{
	t_file	*f;

	if (!(f = input))
		return ;
	ft_putstr(f->line);
	ft_putchar('\n');
	f = f->next;
	while (f != input)
	{
		ft_putstr(f->line);
		ft_putchar('\n');
		f = f->next;
	}
}

int		main(int ac, char **av)
{
	t_asm	a;

	if (ac <= 1 || ac > 3)
		print_usage_exit();
	a.option = set_option(ac, av);
	get_file(&a, av[a.option + 1]);
	lexer(&a);
	return (EXIT_SUCCESS);
}
