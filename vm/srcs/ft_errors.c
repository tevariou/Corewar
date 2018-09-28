/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:24:17 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/28 21:12:32 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mars.h"
#include "libft.h"

void	ft_exit(t_mars *mars, char *error)
{
	write(2, error, ft_strlen(error));
	if (mars)
		free(mars);
	exit(0);
}
