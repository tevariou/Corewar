/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:17:30 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/30 23:11:36 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Live - 0x01
**
** OCP: ❌    Add: ❌      Carry: ❌     Cycle: 10
** @params dest	: DIRECT4 Int
**
** Rapporte le joueur designé par le premier parametre comme etant en vie. 
** L'instruction ecrit sur la sortie standard un message du type 
** "Le joueur $player_name ( $player_id ), a été raporter comme étant en vie". 
** Libre a vous de 'pimper' le message comme bon vous semble, du moment que 
** l'idée passe et qu'il contienne les variables sus nommée. 
** Un joueur ne vie que tant qu'au moins un processus effectue un 
** live avec sont id, et ce au minimun une fois tout les CYCLE_TO_DIE. 
** Si le parametre passé ne correspond a l'id d'aucun joueurs, le comportement 
** est indefinit. A vous de decider si c'est une erreur et que le processus
** crash, ou si osef, l'instruction ne fait rien et on passe a la suite, 
** avec eventuelement en supplément un petit message sur la sortie standard, 
** message incohérent ou message d'avertissement, votre seul limite est celle 
** de votre creativité.
*/

int		ft_live_belong_to_other(t_mars *mars, unsigned i)
{
	t_processus *tmp;

	tmp = mars->process_lst;
	while (tmp)
	{
		if (tmp->player == i)
		{
			tmp->last_cycle_live = mars->current_cycle;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
int		live(t_mars *mars, t_processus *process)
{
	int i;

	i = ft_get_mars_value(mars, 1, REG_SIZE);
	ft_load_register(process, 4, i);
	if (i == process->player)
		process->last_cycle_live = mars->current_cycle;
	else if (ft_live_belong_to_other(mars, i))
		return (SUCCESS);
	else
		return (FALSE);
	return (SUCCESS);
}