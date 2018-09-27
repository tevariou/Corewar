/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 20:14:52 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/28 00:57:20 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <zaz.h>

typedef char byte;
typedef char bool;


# define TRUE 1
# define FALSE 0
# define SUCCESS	1
# define ERROR		-1
# define OPP_ERROR	-2
# define NB_OPPS            16

typedef struct				s_processus
{
	int						player;
	char					*name;
	int						pc;
	unsigned				nbr_of_live;
	unsigned				last_cycle_live;
	struct s_processus		*next;
}							t_processus;

typedef struct				s_mars
{
	byte					*memory;
	unsigned				cycle_to_die;
	unsigned				count_players;
	unsigned				cycle_current;
	unsigned				cycle_delta;
	t_processus				*process_lst;
}							t_mars;

t_mars						*ft_set_mars(int ac, char **av);
void						ft_dump_mars_memory(byte *memory);
t_processus					*ft_argv_have_champ(char **av, int *current_index, int ac);
void						ft_add_processus_to_mars(t_mars *mars, t_processus *process);
int							ft_prepare_mars_memory(t_mars *mars);
int							ft_load_champ_from_file_to_memory(byte *memory, int fd, int start);
void						ft_exit(t_mars *mars, char *error);
void						ft_info_processus(t_processus *process);
void						ft_info_processus(t_processus *process);

/*
** Opertations
*/

int							addition(t_processus *process);
int							aff(t_processus *process);
int							and(t_processus *process);
int							direct_load(t_processus *process);
int							direct_store(t_processus *process);
int							ft_fork(t_processus *process);
int							indirect_load(t_processus *process);
int							indirect_store(t_processus *process);
int							jump(t_processus *process);
int							live(t_processus *process);
int							long_direct_load(t_processus *process);
int							long_fork(t_processus *process);
int							long_indirect_load(t_processus *process);
int							or(t_processus *process);
int							substraction(t_processus *process);
int							xor(t_processus *process);


#endif
