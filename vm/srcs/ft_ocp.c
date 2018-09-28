/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ocp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:14:56 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/28 17:20:44 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include <stdio.h>

int		ft_get_ocp(unsigned ocp)
{
	unsigned	param1;
	unsigned	param2;
	unsigned	dest;

	param1 = ocp >> 2 & 3;
	param2 = ocp >> 4 & 3;
	dest = ocp >> 6 & 3;
	printf("\nP1: [%u]m P2: [%u]: D: [%u]\n", param1, param2, dest);
	return (1);
}
