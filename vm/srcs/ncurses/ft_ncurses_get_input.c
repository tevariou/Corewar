/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses_get_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 10:10:24 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/03 17:49:07 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "visu.h"
#include "../../includes/mars.h"

void	*ft_ncurses_get_input(void *data)
{
	t_visu	*visu;
	int		input;

	visu = (t_visu*)data;
	while (1)
	{
		if ((input = getch()) != -1)
		{
			if (input == 's')
				visu->sleep *= 2;
			if (input == 'f')
				visu->sleep /= 2;
			if (input == ' ')
				visu->pause = (visu->pause == OFF) ? ON : OFF;
		}
	}
	pthread_exit(0);
}
