/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:07:31 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/28 00:59:03 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include <stdio.h>

/*
** Xor - 0x08
**
** OCP: ✅    Add: ✅      Carry: ✅    Cycle: 6
** @params 1 : REG | ID | Direct4 Int
** @params 2 : REG | ID | Direct4 Int
** @params dest	: REG
**
** Effectue un XOR logique entre les deux premiers paramametres 
** et stock le resultat dans le troisieme paramametre. 
** Si la valeur resultante est egale a zero, alors le carry passe a l'etat un, 
** sinon a l'etat zero.
*/

int		xor(t_processus *process)
{
	printf("xor COUCOU\n");
	return (SUCCESS);
}
