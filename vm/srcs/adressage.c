/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adressage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:29:57 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/03 16:51:55 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

unsigned	ft_global_restriction(unsigned address)
{
	if (address >= MEM_SIZE)
		address %= MEM_SIZE;
	return (address);
}
