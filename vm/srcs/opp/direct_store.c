/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:52:07 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/28 00:55:40 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Direct_Store - 0x03
**
** OCP: ✅    Add: ✅      Carry: ✅    Cycle: 5
** @params 1 :  REG
** @params dest	: REG | ID
**
** Transfert direct Registre > RAM / Registre. Charge le contenu
** du registre passé en premier parametre dans le second parametre.
** Si la valeur du premier parametre est egale a zero, alors le carry
** passe a l'etat un, sinon a l'etat zero.
*/

int		direct_store(t_processus *process)
{
	return (SUCCESS);
}
