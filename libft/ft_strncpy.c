/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:54:31 by triou             #+#    #+#             */
/*   Updated: 2018/09/17 18:24:11 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	len;

	if (!dest || !src)
		return (dest);
	len = 0;
	while (len < n && (dest[len] = src[len]))
		len++;
	while (len < n)
		dest[len++] = '\0';
	return (dest);
}
