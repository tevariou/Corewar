/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 10:48:08 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/18 14:58:34 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

void	ft_print_usage(t_mars *mars)
{
	ft_printf("Usage : ./corewar [-dump x]|[-v x | -i | -d][-a x &| -n x]");
	ft_printf(" <*.cor> <...>\n");
	ft_printf("## Champs Options :\n");
	ft_printf("-a X : Change loaded addres to X in RAM\n");
	ft_printf("-n X : Change champs number player to X\n");
	ft_printf("## Visualisator : \n");
	ft_printf("-i : Display visual interface\n");
	ft_printf("-v X: Add verbose\n");
	ft_printf("## Verbose : \n");
	ft_printf("	1 : Lives\n");
	ft_printf("	2 : Cycles\n");
	ft_printf("	4 : Process\n");
	ft_printf("## Others options : \n");
	ft_printf("-dump X : Display RAM every X cycles\n");
	ft_free_mars(mars);
	exit(0);
}
