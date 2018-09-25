/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:55:45 by triou             #+#    #+#             */
/*   Updated: 2018/04/03 19:49:33 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strstr(const char *s, const char *find)
{
	size_t	len;

	if (!(*s) && !(*find))
		return ((char *)s);
	len = ft_strlen(find);
	while (*s)
	{
		if (ft_strnequ(s, find, len))
			return ((char *)s);
		s++;
	}
	return (NULL);
}
