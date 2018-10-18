/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:04:59 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/18 18:57:54 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Aff - 0x10
**
** OCP: ✅    Add: ❌      Carry: ✅    Cycle: 2
** @params dest	: REG
**
** Affiche a l'ecran le char correspondant a la valeure du registre
** passé en parametre, modulo 256. Si ce char est NUL, alors le carry
** passe a l'etat 1, sinon a l'état 0. A vous de choisir le formattage
** de la sortie ecran. Vous pouvez par exemple preciser a chaque aff
** l'id de sont processus d'origine, ou bien attribuer une couleur a
** chaque processus, ou encore attribuer une ligne de aff par processus,
** ou n'importe quoi d'autre avec les processus, l'important reste que
** votre sortie de aff soit le plus swag possible.
*/

int		aff(t_mars *mars, t_processus *process)
{
	int ocp;
	int srcs;

	process->bytes_to_jump = process->pc + 3;
	ocp = ft_get_mars_value(mars, process->pc + 1, 1);
	if (ft_get_param_type(ocp, 1) != REG || ft_get_param_type(ocp, 2)
		|| !ocp || (ocp & 0xffffff)
		|| !ft_is_register(ft_get_mars_value(mars, process->pc + 2, 1)))
		return (ERROR);
	srcs = ft_get_register(process,
		ft_get_mars_value(mars, process->pc + 2, 1));
	ft_printf("%c", srcs % 256);
	return (SUCCESS);
}
