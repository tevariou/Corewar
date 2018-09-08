/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 21:38:57 by triou             #+#    #+#             */
/*   Updated: 2018/07/18 21:39:12 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

ssize_t	ft_binsearch(int *tab, ssize_t size, int n)
{
	ssize_t	left;
	ssize_t	right;
	ssize_t	m;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		m = (right + left) / 2;
		if (tab[m] < n)
			left = m + 1;
		else if (tab[m] > n)
			right = m - 1;
		else
			return (m);
	}
	return (-1);
}
