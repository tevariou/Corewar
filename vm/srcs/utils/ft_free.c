/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:30:33 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/09 11:57:50 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mars.h"

void	ft_free_process(t_processus *p)
{
	t_processus *tmp;

	while (p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
		tmp = NULL;
	}
}

void	ft_free_champion(t_champion *champ)
{
	t_champion *tmp;

	while (champ)
	{
		tmp = champ;
		champ = champ->next;
		free(tmp);
		tmp = NULL;
	}
}

void	ft_free_memory(t_byte **memory)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
		free(memory[i]);
	free(memory);
	memory = NULL;
}

void	*ft_free_current_process(t_processus *process)
{
	free(process);
	return (NULL);
}

void	ft_free_mars(t_mars *mars)
{
	ft_free_memory(mars->memory);
	ft_free_process(mars->process_lst);
	ft_free_champion(mars->champion_lst);
	mars = NULL;
}
