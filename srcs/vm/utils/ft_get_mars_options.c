/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mars_options.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 23:19:55 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/18 15:03:36 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

int		ft_is_dump_option(t_mars *mars, char **av)
{
	char *tmp;

	tmp = NULL;
	if (!*av)
		return (0);
	if (ft_strequ("-dump", *av))
	{
		tmp = av[1];
		while (ft_isdigit(*tmp))
			tmp++;
		if (*tmp)
			return (ERROR);
		mars->dump = ft_atoi(av[1]);
		return (2);
	}
	return (0);
}

int		ft_is_verbose(t_mars *mars, char **av)
{
	char *tmp;

	if (mars->dump != -1)
		ft_print_usage(mars);
	tmp = NULL;
	tmp = av[1];
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp)
		return (ERROR);
	mars->verbose = ft_atoi(av[1]);
	mars->visualisor = VERBOSE;
	mars->ft_display = &ft_verbose;
	return (2);
}

int		ft_is_visualisator(t_mars *mars, char **av)
{
	if (!*av)
		return (0);
	else if (ft_strequ("-i", *av))
	{
		if (mars->dump != -1)
			ft_print_usage(mars);
		mars->ft_display = &ft_ncurses_display;
		mars->visualisor = NCURSE;
		return (SUCCESS);
	}
	else if (ft_strequ("-v", *av))
		return (ft_is_verbose(mars, av));
	return (0);
}
