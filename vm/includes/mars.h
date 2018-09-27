/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 20:14:52 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/26 16:38:34 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <zaz.h>

typedef char byte;
typedef char bool;
#define TRUE 1
#define FALSE 0

typedef struct				s_processus
{
	int						player;
	char					*name;
	int						pc;
	struct s_processus		*next;
}							t_processus;

typedef struct				s_mars
{
	byte					*memory;
	unsigned				cycle_to_die;
	unsigned				count_players;
	unsigned				cycle_current;
	t_processus				*process_lst;
}							t_mars;

t_mars						*ft_set_mars(int ac, char **av);
void						ft_dump_mars_memory(byte *memory);
t_processus					*ft_argv_have_champ(char **av, int *current_index, int ac);
void						ft_add_processus_to_mars(t_mars *mars, t_processus *process);
int							ft_prepare_mars_memory(t_mars *mars);
int							ft_load_champ_from_file_to_memory(byte *memory, int fd, int start);
void						ft_exit(t_mars *mars, char *error);
#endif
