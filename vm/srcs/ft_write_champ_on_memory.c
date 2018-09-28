/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_champ_on_memory.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 22:38:21 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/28 19:56:18 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mars.h"

#include <stdio.h>
int		ft_put_string_on_circular_memory(t_byte *memory, const char *champion, int size, int start)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (memory[start + i])
			return (0);
		memory[(start +  i) % (MEM_SIZE)] = (char)champion[i];
		i++;
	}
	return (1);
}
int		ft_load_champ_from_file_to_memory(t_byte *memory, int fd, int start)
{
	char info[PROG_NAME_LENGTH + COMMENT_LENGTH + SEPARATOR_LINE];
	char buffer[CHAMP_MAX_SIZE + 1];
	int	buff_size;

	read(fd, info, PROG_NAME_LENGTH + COMMENT_LENGTH + SEPARATOR_LINE);
	buff_size = read(fd, buffer, CHAMP_MAX_SIZE);
	if (buff_size >= CHAMP_MAX_SIZE)
		return (0);
	buffer[buff_size] = 0;
	if (!ft_put_string_on_circular_memory(memory, buffer, buff_size, start))
		return (0);
	return (1);
}
