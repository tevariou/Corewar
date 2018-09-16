/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:02:20 by triou             #+#    #+#             */
/*   Updated: 2018/09/15 17:26:24 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	int		i;
	t_asm	a;

	if (ac <= 1 || ac > 3)
		print_usage_exit();
	a.option = set_option(av);
	get_file(&a, av[a.option + 1]);
	print_file(a->input);
	err_free_exit(a, "OK");
	return (EXIT_SUCCESS);
}
