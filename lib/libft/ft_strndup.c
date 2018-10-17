/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:54:54 by triou             #+#    #+#             */
/*   Updated: 2018/09/08 18:36:28 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	char	*dest;
	size_t	len;

	if (!s || !(dest = ft_memalloc((n + 1) * sizeof(*dest))))
		return (NULL);
	if (n > (len = ft_strlen(s)))
		n = len;
	ft_memcpy(dest, s, n);
	dest[n] = '\0';
	return (dest);
}
