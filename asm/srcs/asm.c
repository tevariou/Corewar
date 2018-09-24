/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:02:20 by triou             #+#    #+#             */
/*   Updated: 2018/09/24 17:41:06 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

/*
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
*/

int		main(int ac, char **av)
{
	t_asm	a;
//	t_asm	d;

	if (ac <= 1 || ac > 3)
		print_usage_exit();
	a.option = set_option(ac, av);
//	if (a.option == OPTION_D)
//		decompile
//	else {
//check op.h
		compile_asm(&a, av[a.option + 1]);
		free_input(&a);
		ft_putstr("OK\n");

//}
	return (EXIT_SUCCESS);
}
