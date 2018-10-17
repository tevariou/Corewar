/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:55:23 by triou             #+#    #+#             */
/*   Updated: 2018/04/03 19:47:33 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t	len;

	if (!(*s) && !(*find) && slen)
		return ((char *)s);
	len = ft_strlen(find);
	while (slen-- >= len && *s)
	{
		if (ft_strnequ(s, find, len))
			return ((char *)s);
		s++;
	}
	return (NULL);
}
