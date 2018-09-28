/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indirect_store.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:59:34 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/28 00:55:40 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Indirect_Store - 0x0B
**
** OCP: ✅    Add: ✅      Carry: ✅    Cycle: 25
** @params 1 :  REG
** @params 1 :  REG | ID | DIRECT2 address RAM
** @params dest	: ID | DIRECT2 address RAM
**
** Transfert indirect Registre > RAM. Charge la valeur contenu dans le registre
** passé en premier parametre a l'adresse resultante de l'addition
** des deux derniers paramametres. Si cette valeur est nulle, alors le carry 
** passe a l'etat un, sinon a l'ettat zero.
*/

int		indirect_store(t_processus *process)
{
	return (SUCCESS);
}