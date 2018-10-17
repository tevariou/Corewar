/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:02:56 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 16:59:12 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>

void		check_extension(char *file, const char *ext)
{
	size_t	len;

	if ((len = ft_strlen(file)) <= ft_strlen(ext)
		|| !ft_strequ(file + len - ft_strlen(ext), ext))
		err_free_exit(NULL, WRONG_EXT);
}

bool		dir_len(t_byte op_code)
{
	int	i;

	i = 0;
	while (g_op_tab[i].op_code != op_code)
		i++;
	return (g_op_tab[i].dir_size);
}

bool		ft_tabequ(const char *const *tab, char *needle)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_strequ(tab[i], needle))
			return (true);
		i++;
	}
	return (false);
}

static void	ft_put_hex(unsigned char nb)
{
	const char	*tab;

	tab = HEXA;
	if (nb >= 16)
		ft_put_hex(nb / 16);
	ft_putchar(tab[nb % 16]);
}

void		ft_put_byte(void *n, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)n;
	while (len)
	{
		ft_putstr("0x");
		if (*p < 16)
			ft_putchar('0');
		ft_put_hex(*p++);
		if ((--len))
			ft_putchar(' ');
	}
}
