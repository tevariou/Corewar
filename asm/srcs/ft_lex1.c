/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 21:34:38 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 17:45:11 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>

static char	*is_hexa(char *str)
{
	char	*ptr;

	if (ft_strnequ(str, "0x", 2) || ft_strnequ(str, "0X", 2))
	{
		str += 2;
		ptr = str;
		while (ft_strchr(HEXA, ft_toupper(*str)))
			str++;
		if (ptr == str)
			return (NULL);
		return (str);
	}
	return (NULL);
}

char		*ft_number(char *str)
{
	char	*ptr;

	if ((ptr = is_hexa(str)))
		return (ptr);
	if (*str == '-' || *str == '+')
		str += 1;
	ptr = str;
	while (ft_isdigit(*str))
		str++;
	if (ptr != str)
		return (str);
	return (NULL);
}

char		*ft_instruct(char *str)
{
	int	i;

	i = 15;
	while (i > -1)
	{
		if (ft_strnequ(str, g_op_tab[i].name, ft_strlen(g_op_tab[i].name)))
			return (str + ft_strlen(g_op_tab[i].name));
		i--;
	}
	return (NULL);
}

char		*ft_blanks(char *str)
{
	char	*ptr;

	ptr = str;
	while (ft_isspace(*str))
		str++;
	if (ptr == str)
		return (NULL);
	return (str);
}
