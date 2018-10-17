/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_pc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 18:58:48 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/15 17:53:28 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

void	ft_move_pc(t_mars *mars, t_processus *process)
{
	(void)mars;
	process->pc = ft_global_restriction(process->bytes_to_jump);
}
