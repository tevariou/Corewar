/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verbose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:42:46 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/05 18:35:44 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

int		ft_verbose(t_mars *mars, t_processus *process)
{
	// printf("%d\n", process->player);
	if (mars->verbose == -1)
		return (NO_VERBOSE);
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
			printf("Player %d | %s", process->player, ft_get_opcode_name(mars, process));
			printf(" - %d %d %d\n", process->params[0], process->params[1], process->params[2]);
		}
	}
	if ((mars->verbose >> 3) & 0x01)
		printf("Death\n");
	if ((mars->verbose >> 4) & 0x01)
		printf("PC\n");
	return (1);
}
