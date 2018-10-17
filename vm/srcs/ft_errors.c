/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:24:17 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/17 19:09:11 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mars.h"
#include "libft.h"

void	ft_exit(t_mars *mars, char *error)
{
	if (ft_strequ(error, "bad av"))
		ft_print_usage(mars);
	else
		write(2, error, ft_strlen(error));
	if (mars)
		ft_free_mars(mars);
	exit(0);
}
