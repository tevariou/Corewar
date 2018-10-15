/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 20:14:52 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/15 18:42:27 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "visu.h"
# include <zaz.h>
# include <sys/types.h>
# include <stdio.h>

typedef unsigned char		t_byte;

# define TRUE 				1
# define FALSE 				0
# define SUCCESS			1
# define ERROR				-1
# define OPP_ERROR			-2

# define NB_OPPS            16
# define PROCESS_WAITING	3

# define NO_CARRY			0
# define CARRY				1

# define NO_SIZE			0
# define REG				1
# define INDEX				2
# define DIRECT2			2
# define DIRECT4			4
# define NO_VERBOSE			0

# define PT_SIZE			1001
typedef struct s_mars		t_mars;
typedef struct				s_processus
{
	int						id;
	int						player;
	int						carry;
	char					*name;
	unsigned				pc;
	t_byte					registers[REG_SIZE * REG_NUMBER];
	unsigned				nbr_of_live;
	unsigned				last_cycle_live;
	unsigned				next_instruction_cycle;
	int						(*opcode)(struct s_mars *, struct s_processus *);
	unsigned int			params[3];
	unsigned				bytes_to_jump;
	struct s_processus		*next;
}							t_processus;

typedef struct				s_champion
{
	int						id;
	int						id_color;
	char					*name;
	unsigned				nbr_of_live;
	unsigned				nb_process;
	unsigned				last_cycle_live;
	struct s_champion		*next;
}							t_champion;

struct						s_mars
{
	t_byte					**memory;
	unsigned				cycle_to_die;
	unsigned				count_players;
	unsigned				current_cycle;
	unsigned				cycle_teta;
	unsigned				cycle_delta;
	unsigned				nb_process;
	t_processus				*process_lst[PT_SIZE];
	t_champion				*champion_lst;
	void					(*ft_display)(t_mars *, t_processus *);
	int						visualisor;
	int						dump;
	t_processus				*tmp_jump;
	int						verbose;
	t_visu					visu;
};

/*
** initialisation
*/
t_mars						*ft_set_mars(int ac, char **av);
void						ft_dump_mars_memory(t_byte **memory);
t_processus					*ft_argv_have_champ(t_mars *mars, char **av, int *current_index,
	int ac);
void						ft_add_processus_to_mars(t_mars *mars,
	t_processus *process);
void						ft_add_champ_to_mars(t_mars *mars, t_champion *champion, t_processus *process);
int							ft_prepare_mars_memory(t_mars *mars);
int							ft_load_champ_from_file_to_memory(t_mars *mars,
	t_processus *process, int fd);
void						ft_exit(t_mars *mars, char *error);
unsigned					ft_get_register(t_processus *process, unsigned index);
unsigned					ft_load_register(t_processus *p, unsigned index,
	unsigned value);
int							ft_is_register(int index);
int							ft_memory_is_register(t_mars *mars, int address);
unsigned					ft_get_mars_value(t_mars *mars, unsigned index, unsigned size);
int							ft_get_opcode(t_mars *mars, t_processus *process, t_byte opcode);
char						*ft_get_opcode_name(t_mars *mars, t_processus *process);
unsigned 					ft_load_mars_value(t_mars *mars, unsigned index, unsigned value, unsigned color);
int							ft_is_visualisator(t_mars *mars, char **av);
int							ft_is_dump_option(t_mars *mars, char **av);
void						end_game(t_mars *mars);

/*
** loop during battle
*/
void						loop_through_battle(t_mars *marss);
void						ft_cycles_handler(t_mars *mars);
void						ft_move_pc(t_mars *mars, t_processus *process);

/*
** Debug
*/
void						ft_debug_info(t_mars *mars, t_processus *process);
void						ft_ncurses_display(t_mars *mars, t_processus *process);
void						ft_verbose(t_mars *mars, t_processus *process);
void						ft_info_ram(t_mars *mars);
void						ft_print_usage(t_mars *mars);
void						ft_free_mars(t_mars *mars);
void						*ft_free_current_process(t_processus *process);

/*
** Ncurses
*/
void 						ft_init_ncurses();
void						ft_ncurses_print_live(t_mars *mars);

/*
** restriction addressage
*/
unsigned					ft_global_restriction(unsigned address);
unsigned					ft_local_restriction(unsigned current_pc, unsigned target);
int							ft_op_need_restriction(int (*op)(t_mars *, t_processus *));

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
int							ft_get_params(t_processus *process, t_mars *mars, size_t direct_size, unsigned ocp);
t_processus					*ft_copy_process(t_processus *process, t_mars *mars, short dest);

/*
** gestion des parametres des instructions.
*/
int							ft_get_param_type(int opc, int num_arg);
unsigned					ft_get_srcs(t_mars *mars, t_processus *process, int code, int param_number);
unsigned					ft_get_dest(t_mars *mars, t_processus *process, int code, int dir_size);
int							check_register(int ocp, int index, int value);


/*
** gestion deu tableau de lsite chainee
*/
t_processus   **init_tab_of_process(t_mars *mars);
t_processus     *tab_set_process(t_mars *mars, t_processus *new_process, int dest);
t_processus     *tab_get_next_process(t_mars *mars, int dest);
t_processus    *move_process(t_mars *mars, int current_index, int dest);
t_processus     *tab_see_process(t_mars *mars, int dest);
t_processus     *set_jump_stock(t_mars *mars, t_processus *process);
t_processus     *get_jump_stock(t_mars *mars);

#endif

