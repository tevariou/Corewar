/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:46:18 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/04 19:18:04 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define LIVE               0x01
# define DIRECT_LOAD        0x02
# define DIRECT_STORE       0x03
# define ADDITION           0x04
# define SUBSTRACTION       0x05
# define AND                0x06
# define OR                 0x07
# define XOR                0x08
# define JUMP               0x09
# define INDIRECT_LOAD      0x0A
# define INDIRECT_STORE     0x0B
# define FORK               0x0C
# define L_DIRECT_LOAD      0x0D
# define L_INDERECT_LOAD    0x0E
# define L_FORK             0x0F
# define AFF                0x10

typedef struct				s_pf_opp
{
	unsigned				value;
	int						(*f)(t_mars *, t_processus *);
	unsigned				latence;
}							t_pf_opp;

t_pf_opp					g_opps[NB_OPPS] =
{
	{LIVE, &live, 10},
	{DIRECT_LOAD, &direct_load, 5},
	{DIRECT_STORE, &direct_store, 5},
	{ADDITION, &addition, 10},
	{SUBSTRACTION, &substraction, 10},
	{AND, &and, 6},
	{OR, &or, 6},
	{XOR, &xor, 6},
	{JUMP, &jump, 20},
	{INDIRECT_LOAD, &indirect_load, 25},
	{INDIRECT_STORE, &indirect_store, 25},
	{FORK, &ft_fork, 8},
	{L_DIRECT_LOAD, &long_direct_load, 10},
	{L_INDERECT_LOAD, &long_indirect_load, 50},
	{L_FORK, &long_fork, 1000},
	{AFF, &aff, 2},
};

#endif
