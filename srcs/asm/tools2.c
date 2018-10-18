/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:43:31 by triou             #+#    #+#             */
/*   Updated: 2018/10/12 20:06:26 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>

void		ft_put_uint(unsigned int nb, int fd)
{
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd('0' + nb % 10, fd);
}

char		*set_extension(t_asm *a, char *file,
							const char *dest, const char *src)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(dest) - ft_strlen(src);
	if (!(ret = ft_memalloc((ft_strlen(file) + 1 + len) * sizeof(*ret))))
		err_free_exit(a, NULL);
	ft_strncpy(ret, file, ft_strlen(file) - ft_strlen(src));
	ft_strcat(ret, dest);
	return (ret);
}

void		reverse_bytes(void *n, size_t size)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	tmp;

	p = (unsigned char *)n;
	i = 0;
	while (i < size / 2)
	{
		tmp = p[i];
		p[i] = p[size - i - 1];
		p[size - i - 1] = tmp;
		i++;
	}
}
