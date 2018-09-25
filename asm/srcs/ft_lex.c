/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 21:34:38 by triou             #+#    #+#             */
/*   Updated: 2018/09/24 22:07:17 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

char	*ft_str_label(char *str)
{
	char	*ptr;

	ptr = str;
	while (ft_strchr(LABEL_CHARS, *ptr))
		ptr++;
	if (ptr == str || *ptr++ != LABEL_CHAR)
		return (NULL);
	return (ptr);
}

char	*ft_label_str(char *str)
{
	char	*ptr;

	if (*str++ != LABEL_CHAR)
		return (NULL);
	ptr = str;
	while (ft_strchr(LABEL_CHARS, *ptr))
		ptr++;
	if (ptr == str)
		return (NULL);
	return (ptr);
}

char	*ft_direct(char *str)
{
	if (*str++ != DIRECT_CHAR)
		return (NULL);
	return (str);
}

char	*ft_separator(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str++ != SEPARATOR_CHAR)
		return (NULL);
	while (ft_isspace(*str))
		str++;
	return (str);
}

char	*ft_reg(char *str)
{
	char	*ptr;

	if (*str++ != 'r')
		return (NULL);
	ptr = str;
	while (ft_isdigit(*str))
		str++;
	if (ptr == str)
		return (NULL);
	return (str);
}

char	*ft_op(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str != '+' && *str != '-')
		return (NULL);
	str += 1;
	while (ft_isspace(*str))
		str++;
	return (str);
}

static char	*is_hexa_maj(char *str)
{
	char	*ptr;

	if (ft_strnequ(str, "0X", 2))
	{
		str += 2;
		ptr = str;
		while (ft_strchr(HEXA_MAJ, *str))
			str++;
		if (ptr == str)
			return (NULL);
		return (str);
	}
	return (NULL);
}

static char	*is_hexa_min(char *str)
{
	char	*ptr;

	if (ft_strnequ(str, "0x", 2))
	{
		str += 2;
		ptr = str;
		while (ft_strchr(HEXA_MIN, *str))
			str++;
		if (ptr == str)
			return (NULL);
		return (str);
	}
	return (NULL);
}

char	*ft_number(char *str)
{
	char	*ptr;

	if ((ptr = is_hexa_min(str)) || (ptr = is_hexa_maj(str)))
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

char	*ft_instruct(char *str)
{
	int	i;

	i = 15;
	while (i > -1)
	{
		if (ft_strnequ(str, g_op_tab[i].instruct, ft_strlen(g_op_tab[i].instruct)))
			return (str + ft_strlen(g_op_tab[i].instruct));
		i--;
	}
	return (NULL);
}

char	*ft_blanks(char *str)
{
	char	*ptr;

	ptr = str;
	while (ft_isspace(*str))
		str++;
	if (ptr == str)
		return (NULL);
	return (str);
}

