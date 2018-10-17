/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:52:50 by triou             #+#    #+#             */
/*   Updated: 2018/06/20 18:57:35 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;

	if (!(dest = (char *)malloc((ft_strlen(s) + 1) * sizeof(*dest))))
		return (NULL);
	return (ft_strcpy(dest, s));
}
