/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:22:43 by triou             #+#    #+#             */
/*   Updated: 2018/09/12 20:25:42 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

t_bool	set_option(int ac, char **av)
{
	if (ac == 3 && ft_strequ(av[1], OPTION))
		return (TRUE);
	else if (ac == 2 && ft_strequ(av[1], OPTION))
		print_usage_exit();
	return (FALSE);
}
