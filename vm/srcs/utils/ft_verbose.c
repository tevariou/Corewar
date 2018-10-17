/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verbose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:42:46 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/16 16:37:56 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

void		ft_verbose(t_mars *mars, t_processus *process)
{
	// printf("%d\n", process->player);
	if (mars->verbose == -1)
		return ;
	if (mars->verbose & 0x01)
	{
		if (mars->current_cycle == process->last_cycle_live)
			printf("Player %d has been set as alive!!\n", process->player);
	}
	if ((mars->verbose >> 1) & 0x01)
	{
		printf("Current cycle %d\n", mars->current_cycle);
		if (mars->current_cycle == mars->cycle_to_die)
			printf("Cycle to die is now %d\n",
				mars->current_cycle - mars->cycle_delta);
	}
	if ((mars->verbose >> 2) & 0x01)
	{
		if (ft_get_opcode_name(mars, process) != NULL)
		{
			printf("Proc %d | %s", process->id, ft_get_opcode_name(mars, process));
			printf(" - %d %d %d\n", process->params[0], process->params[1], process->params[2]);
		}
	}
	if ((mars->verbose >> 3) & 0x01)
		printf("Death\n");
	if ((mars->verbose >> 4) & 0x01)
		printf("PC\n");
}

void		ft_display_no_verbose_entry(t_mars *mars)
{
	t_champion *champ;

	printf("Introducing challengers... \n\n");
	champ = mars->champion_lst;
	while (champ)
	{
		printf("*** %-10s,weigthing %4d bytes, is a new challenger *** \n",
			champ->header.prog_name, champ->header.prog_size);
		champ = champ->next;
	}
}