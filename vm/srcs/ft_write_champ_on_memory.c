/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_champ_on_memory.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 22:38:21 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/27 15:46:46 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mars.h"

#include <stdio.h>
void	ft_put_string_on_circular_memory(byte *memory, const char *champion, int size, int start)
{
	int i;

	i = 0;
	while (i < size)
	{
		memory[(start +  i) % (MEM_SIZE)] = (char)champion[i];
		i++;
	}
}
int		ft_load_champ_from_file_to_memory(byte *memory, int fd, int start)
{
	char info[PROG_NAME_LENGTH + COMMENT_LENGTH + 1];
	char buffer[CHAMP_MAX_SIZE + 1];
	int	buff_size;

	read(fd, info, PROG_NAME_LENGTH + COMMENT_LENGTH);
	buff_size = read(fd, buffer, CHAMP_MAX_SIZE);
	printf("%d\n", buff_size);
	if (buff_size >= CHAMP_MAX_SIZE)
		return (0);
	buffer[buff_size] = 0;
	ft_put_string_on_circular_memory(memory, buffer, buff_size, start);
	return (1);
}
