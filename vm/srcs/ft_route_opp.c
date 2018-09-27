/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_route_opp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:14:56 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/28 00:57:37 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include "asm.h"

void		ft_init_opps(t_pf_opp opps[NB_OPPS])
{
	int		i;

	i = 0;
	while (++i != NB_OPPS)
		opps[i].value = i;
	opps[0].f = &live;
	opps[1].f = &direct_load;
	opps[2].f = &direct_store;
	opps[3].f = &addition;
	opps[4].f = &substraction;
	opps[5].f = &and;
	opps[6].f = &or;
	opps[7].f = &xor;
	opps[8].f = &jump;
	opps[9].f = &indirect_load;
	opps[10].f = &indirect_store;
	opps[11].f = &ft_fork;
	opps[12].f = &long_direct_load;
	opps[13].f = &long_indirect_load;
	opps[14].f = &long_fork;
	opps[15].f = &aff;
}
