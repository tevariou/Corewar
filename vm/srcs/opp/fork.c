/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 22:53:53 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/04 16:11:53 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

/*
** Fork - 0x0C
**
** OCP: ❌   Add: ✅      Carry: ❌   Cycle: 800
** @params dest	: DIRECT2 Address RAM
**
** Genere un nouveau processus a l'adresse passée en parametre par copie 
** du processus appelant. Le nouveau processus garde donc l'etat de tout 
** les registres et du carry, seul le PC differe 
** ( sauf dans le cas d'un fork %0 ).
*/

int		ft_fork(t_mars *mars, t_processus *process)
{
	(void) mars;
	(void) process;
	return (SUCCESS);
}

