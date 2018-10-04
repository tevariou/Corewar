/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_processus_to_mars.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:29:00 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/30 20:43:20 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mars.h"
#include "libft.h"
#include <stdio.h>

t_processus		*ft_new_empty_processus(void)
{
	t_processus *process;
	unsigned	iterator_register;

	process = malloc(sizeof(t_processus));
	if (!process)
		return (NULL);
	iterator_register = 0;
	process->player = 0;
	process->pc = 0;
	process->next_instruction_cycle = 0;
	process->name = NULL;
	process->next = NULL;
	process->opcode = 0;
	process->next_instruction_cycle = 0;
	while (iterator_register < REG_NUMBER * REG_SIZE)
		process->registers[iterator_register++] = 0;
	return (process);
}

int				ft_add_parameter_to_processus(t_processus *process, char **av)
{
	char *tmp;

	tmp = NULL;
	if (!*av)
		return (0);
	else if (ft_strequ("-n", *av))
	{
		tmp = av[1];
		while (ft_isdigit(*tmp))
			tmp++;
		if (*tmp)
			return (-1);
		process->player = atoi(av[1]);
		return (2);
	}
	else if (ft_strequ("-a", *av))
	{
		tmp = av[1];
		while (ft_isdigit(*tmp))
			tmp++;
		if (*tmp)
			return (-1);
		process->pc = atoi(av[1]);
		return (2);
	}
	else
	{
		tmp = *av;
		while (*tmp)
		{
			++tmp;
			if (ft_strequ(".cor", tmp))
			{
				process->name = *av;
				return (1);
			}
		}
		return (-1);
	}
}

/*
** loop through av to find champion since last champion saved.
** every thing before is checked as an option. if an option is not valid or a
** champion is not found after options, the process exit and the function
** return a NULL pointer. Else a new processus is returned..
*/

t_processus		*ft_argv_have_champ(char **av, int *current_index, int ac)
{
	t_processus *process;
	int			i;
	int			k;

	i = 0;
	k = 0;
	process = ft_new_empty_processus();
	if (!process)
		return (NULL);
	while (!process->name && (*current_index + i) < ac)
	{
		if ((k = ft_add_parameter_to_processus(process,
						&av[*current_index + i])) == -1)
			return (NULL);
		i = i + k;
	}
	if (!process->name)
		return (NULL);
	*current_index += i;
	return (process);
}

/*
** add a processus at the begining of the lst of mars processus.
*/

void			ft_add_processus_to_mars(t_mars *mars, t_processus *process)
{
	process->next = mars->process_lst;
	mars->process_lst = process;
}