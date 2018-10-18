/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:46:18 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/10/18 19:04:49 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

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

# define DIRECT_2			2
# define DIRECT_4			4
# define NO_DIRECT			0

typedef struct				s_pf_opp
{
	unsigned				value;
	int						(*f)(t_mars *, t_processus *);
	unsigned				latence;
	int						direct_size;
	char					*name;
}							t_pf_opp;

t_pf_opp					g_opps[NB_OPPS] =
{
	{LIVE, &live, 10, DIRECT_4, "live"},
	{DIRECT_LOAD, &direct_load, 5, DIRECT_4, "ld"},
	{DIRECT_STORE, &direct_store, 5, NO_DIRECT, "st"},
	{ADDITION, &addition, 10, NO_DIRECT, "add"},
	{SUBSTRACTION, &substraction, 10, NO_DIRECT, "sub"},
	{AND, &and, 6, DIRECT_4, "and"},
	{OR, &or, 6, DIRECT_4, "or"},
	{XOR, &xor, 6, DIRECT_4, "xor"},
	{JUMP, &jump, 20, DIRECT_2, "zjump"},
	{INDIRECT_LOAD, &indirect_load, 25, DIRECT_2, "ldi"},
	{INDIRECT_STORE, &indirect_store, 25, DIRECT_2, "sti"},
	{FORK, &ft_fork, 800, DIRECT_2, "fork"},
	{L_DIRECT_LOAD, &long_direct_load, 10, DIRECT_4, "lld"},
	{L_INDERECT_LOAD, &long_indirect_load, 50, DIRECT_2, "lldi"},
	{L_FORK, &long_fork, 1000, DIRECT_2, "lfork"},
	{AFF, &aff, 2, NO_DIRECT, "affs"}
};

#endif
