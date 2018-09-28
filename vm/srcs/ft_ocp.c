/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ocp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:14:56 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/28 20:11:25 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include <stdio.h>

int		ft_get_ocp(t_processus *process, unsigned ocp)
{
	unsigned	param1;
	unsigned	param2;
	unsigned	dest;

	process->param1 = ocp >> 2 & 3;
	process->param2 = ocp >> 4 & 3;
	process->dest = ocp >> 6 & 3;
	printf("\nP1: [%u]m P2: [%u]: D: [%u]\n", process->param1, process->param2,
		process->dest);
	return (1);
}
