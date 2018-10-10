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

void	put_reg(int in, char **out, t_bool end)
{
	t_byte	buff;
	char	*n;

	if (read(in, &buff, sizeof(buff)) <= 0)
		decompile_error(out);
	ft_buffer(out, "r");
	if (!(n = ft_itoa(buff)))
		decompile_error(out);
	ft_buffer(out, n);
	free(n);
	if (!end)
		ft_buffer(out, ", ");
}

void	put_ind(int in, char **out, t_bool end)
{
	short	buff;
	char	*n;

	if (read(in, &buff, sizeof(buff)) <= 0)
		decompile_error(out);
	reverse_bytes(&buff, sizeof(buff));
	if (!(n = ft_itoa(buff)))
		decompile_error(out);
	ft_buffer(out, n);
	free(n);
	if (!end)
		ft_buffer(out, ", ");
}

void	put_dir(int in, char **out, t_bool end, t_bool len)
{
	int		buff;
	char	*n;

	ft_buffer(out, "%");
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
		ft_buffer(out, ", ");
}
