/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 18:59:09 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/18 19:00:04 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

t_processus	*set_jump_stock(t_mars *mars, t_processus *process)
{
	if (!process)
		return (NULL);
	process->next = mars->tmp_jump;
	mars->tmp_jump = process;
	return (process);
}

t_processus	*get_jump_stock(t_mars *mars)
{
	t_processus *get;

	if (!mars->tmp_jump)
		return (NULL);
	get = mars->tmp_jump;
	mars->tmp_jump = get->next;
	return (get);
}
