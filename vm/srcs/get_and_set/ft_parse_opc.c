/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_opc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:05:55 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/10 16:26:54 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include "libft.h"


int ft_get_param_type(int opc, int num_arg)
{
    return ((opc >> (8 - num_arg * 2) & 3));
}

int check_register(int ocp, int index, int value)
{
    if (ft_get_param_type(ocp, index) == REG_CODE && !ft_is_register(value))
        return (0);
    return (1);
}
