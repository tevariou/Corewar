/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:55:36 by triou             #+#    #+#             */
/*   Updated: 2018/09/08 18:40:31 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordlen(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static size_t	ft_wordcount(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	if (!(*s))
		return (0);
	while (*s && *s != c)
		s++;
	return (1 + ft_wordcount(s, c));
}

static	int		ft_worddup(char const *s, char c, char **tab)
{
	size_t	len;

	while (*s && *s == c)
		s++;
	if (!(*s))
	{
		*tab = NULL;
		return (1);
	}
	len = ft_wordlen(s, c);
	if (!(*tab = ft_strndup(s, len)))
		return (0);
	if (!ft_worddup(s + len, c, tab + 1))
	{
		free(*tab);
		return (0);
	}
	return (1);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;

	if (!s || !(tab = ft_memalloc((ft_wordcount(s, c) + 1) * sizeof(*tab))))
		return (NULL);
	if (!ft_worddup(s, c, tab))
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}
