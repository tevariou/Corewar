/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:57:11 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/27 18:02:34 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "mars.h"

void	ft_info_processus(t_processus *process)
{
	if (!process)
		ft_exit(NULL, "no process");
	ft_putstr(process->name);
	ft_putchar('\n');
	ft_putnbr(process->pc);
	ft_putchar('\n');
	ft_putnbr(process->player);
	ft_putchar('\n');
}
