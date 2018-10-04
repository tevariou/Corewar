/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_champ_on_memory.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 22:38:21 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/03 18:11:14 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mars.h"
#include <stdio.h>

int		ft_put_string_on_circular_memory(t_mars *mars, t_processus *process,
		const char *champion, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (mars->memory[process->pc + i][0] % MEM_SIZE)
			return (0);
		mars->memory[(process->pc + i) % (MEM_SIZE)][0] = (char)champion[i];
		mars->memory[(process->pc + i) % (MEM_SIZE)][1] = process->player;
		i++;
	}
	return (1);
}

int		ft_load_champ_from_file_to_memory(t_mars *mars, t_processus *process, int fd)
{
	char	info[PROG_NAME_LENGTH + COMMENT_LENGTH + SEPARATOR_LINE];
	char	buffer[CHAMP_MAX_SIZE + 1];
	int		buff_size;

	read(fd, info, PROG_NAME_LENGTH + COMMENT_LENGTH + SEPARATOR_LINE);
	buff_size = read(fd, buffer, CHAMP_MAX_SIZE);
	if (buff_size >= CHAMP_MAX_SIZE)
		return (0);
	buffer[buff_size] = 0;
	if (!ft_put_string_on_circular_memory(mars, process, buffer, buff_size))
		return (0);
	return (1);
}
