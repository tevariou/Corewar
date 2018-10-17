/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 10:48:08 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/17 19:25:48 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mars.h"

void	ft_print_usage(t_mars *mars)
{
	printf("Usage : ./corewar [-dump x]|[-v x | -i | -d][-a x &| -n x]");
	printf(" <*.cor> <...>\n");
	printf("## Champs Options :\n");
	printf("-a X : Change loaded addres to X in RAM\n");
	printf("-n X : Change champs number player to X\n");
	printf("## Visualisator : \n");
	printf("-i : Display visual interface\n");
	printf("-v X: Add verbose\n");
	printf("## Verbose : \n");
	printf("	1 : Lives\n");
	printf("	2 : Cycles\n");
	printf("	4 : Process\n");
	printf("## Others options : \n");
	printf("-dump X : Display RAM every X cycles\n");
	ft_free_mars(mars);
	exit(0);
}
