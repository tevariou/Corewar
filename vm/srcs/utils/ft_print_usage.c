/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 10:48:08 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/05 12:47:34 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

void	ft_print_usage(void)
{
	printf("Usage : ./corewar [-dump x | -i | -d][champs options] <*.cor> <...>\n");
	printf("## Champs Options :\n");
	printf("-a X : Change loaded addres to X in RAM\n");
	printf("-n X : Change champs number player to X\n");
	printf("## Visualisator : \n");
	printf("-i : Display visual interface\n");
	printf("-d : Display debug interface\n");
	printf("## Others options : \n");
	printf("-dump X : Display RAM every X cycles\n");
}