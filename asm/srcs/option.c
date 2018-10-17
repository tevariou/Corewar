/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:22:43 by triou             #+#    #+#             */
/*   Updated: 2018/09/17 18:25:24 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int	set_option(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_strequ(av[1], OPTION_STR_A))
			return (OPTION_A);
		else if (ft_strequ(av[1], OPTION_STR_D))
			return (OPTION_D);
		else
			print_usage_exit();
	}
	else if (ac == 2 && (ft_strequ(av[1], OPTION_STR_A)
		|| ft_strequ(av[1], OPTION_STR_D)))
		print_usage_exit();
	return (0);
}
