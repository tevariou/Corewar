/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:46:34 by triou             #+#    #+#             */
/*   Updated: 2018/04/03 23:56:54 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_ntostr(unsigned int nb, char *new, size_t len)
{
	if (nb >= 10)
		ft_ntostr(nb / 10, new, len - 1);
	new[len] = '0' + nb % 10;
}

char			*ft_itoa(int n)
{
	char			*new;
	size_t			len;
	int				cpy;

	len = (n < 0) ? 2 : 1;
	cpy = n;
	while ((cpy /= 10))
		len++;
	if (!(new = (char *)malloc((len + 1) * sizeof(*new))))
		return (NULL);
	new[len] = '\0';
	if (n < 0)
	{
		*new = '-';
		ft_ntostr((unsigned int)(-n), new, len - 1);
	}
	else
		ft_ntostr((unsigned int)n, new, len - 1);
	return (new);
}
