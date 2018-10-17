/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:53:30 by triou             #+#    #+#             */
/*   Updated: 2018/09/08 18:28:16 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	new = ft_memalloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*new));
	if (!new)
		return (NULL);
	return (ft_strcat(ft_strcpy(new, s1), s2));
}
