/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 20:14:52 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/29 18:55:22 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <zaz.h>
#include <sys/types.h>
typedef char				t_byte;

# define TRUE 				1
# define FALSE 				0
# define SUCCESS			1
# define ERROR				-1
# define OPP_ERROR			-2

# define NB_OPPS            16
# define PROCESS_WAITING	3

# define REG				1
# define INDEX				2
# define DIRECT2			2
# define DIRECT4			4


typedef struct				s_processus
{
	int						player;
	char					*name;
	int						pc;
	t_byte					registers[REG_SIZE * REG_NUMBER];
	unsigned				nbr_of_live;
	unsigned				last_cycle_live;
	unsigned				next_instruction_cycle;
	unsigned				define_params[3];
	unsigned				size_params[3];
	unsigned int			params[3];
	struct s_processus		*next;
}							t_processus;

typedef struct				s_mars
{
	t_byte					*memory;
	unsigned				cycle_to_die;
	unsigned				count_players;
	unsigned				current_cycle;
	unsigned				cycle_teta;
	unsigned				cycle_delta;
	t_processus				*process_lst;
}							t_mars;

/*
** initialisation
*/
t_mars						*ft_set_mars(int ac, char **av);
void						ft_dump_mars_memory(t_byte *memory);
t_processus					*ft_argv_have_champ(char **av, int *current_index,
	int ac);
void						ft_add_processus_to_mars(t_mars *mars,
	t_processus *process);
int							ft_prepare_mars_memory(t_mars *mars);
int							ft_load_champ_from_file_to_memory(t_byte *memory,
	int fd, int start);
void						ft_exit(t_mars *mars, char *error);
int							ft_get_register(t_processus *process, unsigned index);
int							ft_load_register(t_processus *p, unsigned index, int value);
void						ft_info_processus(t_processus *process);
void						ft_info_processus(t_processus *process);
int							ft_get_register(t_processus *process,
	unsigned index);
int							ft_load_register(t_processus *p, unsigned index,
	int value);
int							ft_get_opcode(t_mars *mars, t_processus *process, t_byte opcode);
int							ft_get_ocp(t_processus *process, unsigned ocp);

/*
** loop during battle
*/
void						loop_through_battle(t_mars *mars);
void						ft_cycles_handler(t_mars *mars);

/*
** Debug
*/
void						ft_info_processus(t_processus *process);
void						ft_info_ram(t_mars *mars);
void						ft_debug_info(t_mars *mars);

/*
** Opertations
*/

int							addition(t_mars *mars, t_processus *process);
int							aff(t_mars *mars, t_processus *process);
int							and(t_mars *mars, t_processus *process);
int							direct_load(t_mars *mars, t_processus *process);
int							direct_store(t_mars *mars, t_processus *process);
int							ft_fork(t_mars *mars, t_processus *process);
int							indirect_load(t_mars *mars, t_processus *process);
int							indirect_store(t_mars *mars, t_processus *process);
int							jump(t_mars *mars, t_processus *process);
int							live(t_mars *mars, t_processus *process);
int							long_direct_load(t_mars *mars, t_processus *process);
int							long_fork(t_mars *mars, t_processus *process);
int							long_indirect_load(t_mars *mars,
	t_processus *process);
int							or(t_mars *mars, t_processus *process);
int							substraction(t_mars *mars, t_processus *process);
int							xor(t_mars *mars, t_processus *process);
int							ft_get_params(t_processus *process, t_mars *mars, size_t direct_size);

#endif
