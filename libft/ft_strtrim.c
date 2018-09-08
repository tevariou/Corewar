/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:55:59 by triou             #+#    #+#             */
/*   Updated: 2018/04/03 23:47:30 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	size_t	len;

	while (ft_isspace(*s))
		s++;
	if ((len = ft_strlen(s)))
	{
		while (ft_isspace(s[len - 1]))
			len--;
	}
	return (ft_strndup(s, len));
}
