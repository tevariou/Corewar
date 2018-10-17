/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompile_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:28:37 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 17:51:48 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	ft_buffer(char **out, char *new)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(*out, new)))
		decompile_error(out);
	free(*out);
	*out = tmp;
}

void	put_reg(int in, char **out, bool end)
{
	t_byte	buff;
	char	*n;
	char	sep[3];

	sep[0] = SEPARATOR_CHAR;
	sep[1] = ' ';
	sep[2] = '\0';
	if (read(in, &buff, sizeof(buff)) <= 0)
		decompile_error(out);
	ft_buffer(out, "r");
	if (!(n = ft_itoa(buff)))
		decompile_error(out);
	ft_buffer(out, n);
	free(n);
	if (!end)
		ft_buffer(out, sep);
}

void	put_ind(int in, char **out, bool end)
{
	short	buff;
	char	*n;
	char	sep[3];

	sep[0] = SEPARATOR_CHAR;
	sep[1] = ' ';
	sep[2] = '\0';
	if (read(in, &buff, sizeof(buff)) <= 0)
		decompile_error(out);
	reverse_bytes(&buff, sizeof(buff));
	if (!(n = ft_itoa(buff)))
		decompile_error(out);
	ft_buffer(out, n);
	free(n);
	if (!end)
		ft_buffer(out, sep);
}

void	put_dir(int in, char **out, bool end, bool len)
{
	int		buff;
	char	*n;
	char	dir[2];
	char	sep[3];

	sep[0] = SEPARATOR_CHAR;
	sep[1] = ' ';
	sep[2] = '\0';
	dir[0] = DIRECT_CHAR;
	dir[1] = '\0';
	ft_buffer(out, dir);
	if (len)
	{
		put_ind(in, out, end);
		return ;
	}
	if (read(in, &buff, sizeof(buff)) <= 0)
		decompile_error(out);
	reverse_bytes(&buff, sizeof(buff));
	if (!(n = ft_itoa(buff)))
		decompile_error(out);
	ft_buffer(out, n);
	free(n);
	if (!end)
		ft_buffer(out, sep);
}
