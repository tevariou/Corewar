/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:55:12 by triou             #+#    #+#             */
/*   Updated: 2018/09/12 21:58:22 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h";

static t_bool	check_extension(char *file)
{
	size_t	len;

	if ((len = ft_strlen(file)) <= 2 || !ft_strequ(file + len - 2, EXT))
	{
		ft_puterr(file);
		ft_puterr(":\n");
		ft_puterr(WRONG_EXT);
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	read_file(t_asm *a, char *line)
{
	int		fd;
	int		ret;
	char	*line;

	a->input = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		sys_free_exit(a);
	line = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < -1)
			sys_free_exit(a);
		add_input_line(a, line);
		line = NULL;
	}
	if (close(fd) < 0)
		sys_free_exit(a);
}

void		compile_file(t_asm *a, char *file)
{
	int		fd;
	t_asm	a;

	if (!check_extension(file))
		return ;
		
}
