/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:29:00 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/16 18:04:54 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"

void    end_game(t_mars *mars)
{
    t_champion  *c;
    t_champion  *winner;

    c = mars->champion_lst;
    winner = mars->champion_lst;
    while (c)
    {
        if (c->last_cycle_live > winner->last_cycle_live)
            winner = c;
            c = c->next;
    }
    printf("\nAnd the winner is : %s \n", winner->header.prog_name);
    printf("He says: %s\n", winner->header.comment);
    ft_exit(mars, "");
}
