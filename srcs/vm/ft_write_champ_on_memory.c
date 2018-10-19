/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_champ_on_memory.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 22:38:21 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/19 19:16:08 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

int			ft_put_string_on_circular_memory(t_mars *mars, t_processus *process,
		const char *champion, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (mars->memory[(process->pc + i) % MEM_SIZE][0])
			return (0);
		mars->memory[(process->pc + i) % (MEM_SIZE)][0] = (char)champion[i];
		mars->memory[(process->pc + i) % (MEM_SIZE)][1] = process->id_color;
		i++;
	}
	return (1);
}

static int	ft_read_information(t_mars *mars, t_processus *process, int fd)
{
	t_champion		*champ;
	unsigned char	tmp[5];
	int				l;

	ft_bzero(tmp, 5);
	champ = mars->champion_lst;
	while (champ && champ->id != process->player)
		champ = champ->next;
	read(fd, tmp, 4);
	tmp[4] = 0;
	champ->header.magic = tmp[0] * 256 * 256 * 256 + tmp[1]
		* 256 * 256 + tmp[2] * 256 + tmp[3];
	if (champ->header.magic != COREWAR_EXEC_MAGIC)
		ft_exit(mars, E_NOT_COR);
	if ((l = read(fd, champ->header.prog_name, PROG_NAME_LENGTH)) != -1)
		champ->header.prog_name[l] = 0;
	read(fd, tmp, 4);
	read(fd, tmp, 4);
	if ((champ->header.prog_size = tmp[0] * 256 * 256 * 256 + tmp[1]
		* 256 * 256 + tmp[2] * 256 + tmp[3]) == 0 || champ->header.prog_size
			> CHAMP_MAX_SIZE)
		ft_exit(mars, E_NO_CODE);
	if ((l = read(fd, champ->header.comment, COMMENT_LENGTH + 4)) != -1)
		champ->header.comment[l] = 0;
	return (1);
}

int			ft_load_champ_from_file_to_memory(t_mars *mars,
	t_processus *process, int fd)
{
	char		buffer[CHAMP_MAX_SIZE + 1];
	int			buff_size;

	ft_read_information(mars, process, fd);
	buff_size = read(fd, buffer, CHAMP_MAX_SIZE);
	if (buff_size <= 0)
		return (0);
	if (buff_size >= CHAMP_MAX_SIZE)
		return (0);
	buffer[buff_size] = 0;
	if (!ft_put_string_on_circular_memory(mars, process, buffer, buff_size))
		return (0);
	return (1);
}
