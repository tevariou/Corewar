/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:52:30 by triou             #+#    #+#             */
/*   Updated: 2018/09/08 18:22:32 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	len;

	len = 0;
	if (dest && src)
	{
		while ((dest[len] = src[len]))
			len++;
	}
	return (dest);
}
