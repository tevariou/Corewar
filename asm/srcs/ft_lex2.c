/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:43:36 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 17:44:23 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
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
