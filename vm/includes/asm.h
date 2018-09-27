/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:46:18 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/28 00:56:36 by lmazeaud         ###   ########.fr       */
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
	int						(*f)(t_processus *);
}							t_pf_opp;

void		ft_init_opps(t_pf_opp opps[NB_OPPS]);

#endif
