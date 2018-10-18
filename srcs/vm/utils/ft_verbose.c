/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verbose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:42:46 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/18 14:59:59 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

void		ft_verbose(t_mars *mars, t_processus *process)
{
	if (mars->verbose == -1)
		return ;
	if (mars->verbose & 0x01)
	{
		if (mars->current_cycle == process->last_cycle_live)
			ft_printf("Player %d has been set as alive!!\n", process->player);
	}
	if ((mars->verbose >> 1) & 0x01)
		ft_printf("Current cycle %d\n", mars->current_cycle);
	if ((mars->verbose >> 2) & 0x01)
		if (ft_get_opcode_name(mars, process) != NULL)
			ft_printf("Proc %d | %s\n", process->id,
				ft_get_opcode_name(mars, process));
}

void		ft_display_no_verbose_entry(t_mars *mars)
{
	t_champion *champ;

	ft_printf("Introducing challengers... \n\n");
	champ = mars->champion_lst;
	while (champ)
	{
		ft_printf("*** %-10s,weigthing %4d bytes, is a new challenger *** \n",
			champ->header.prog_name, champ->header.prog_size);
		champ = champ->next;
	}
}
