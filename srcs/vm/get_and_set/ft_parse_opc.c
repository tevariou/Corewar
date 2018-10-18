/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_opc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:05:55 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/18 15:03:51 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

int	ft_get_param_type(int opc, int num_arg)
{
	return ((opc >> (8 - num_arg * 2) & 3));
}

int	check_register(int ocp, int index, int value)
{
	if (ft_get_param_type(ocp, index) == REG_CODE && !ft_is_register(value))
		return (0);
	return (1);
}
