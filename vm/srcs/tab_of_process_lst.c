/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_of_process_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <abiestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:49:14 by abiestro          #+#    #+#             */
/*   Updated: 2018/10/15 17:19:41 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mars.h"
#include "libft.h"


t_processus     *set_jump_stock(t_mars *mars, t_processus *process)
{
    if (!process)
        return (NULL);
    process->next = mars->tmp_jump;
    mars->tmp_jump = process;
    return (process);
}

t_processus     *get_jump_stock(t_mars *mars)
{
    t_processus *get;

    if (!mars->tmp_jump)
        return (NULL);
    get = mars->tmp_jump;
    mars->tmp_jump = get->next;
    return (get);
}

t_processus   **init_tab_of_process(t_mars *mars)
{
    ft_memset(mars->process_lst, 0, sizeof(t_processus *) * PT_SIZE);
    return (mars->process_lst);
}

t_processus     *tab_set_process(t_mars *mars, t_processus *new_process, int dest)
{
    t_processus *tmp;
    t_processus *tmp2;

    if (!new_process)
        return (NULL);
    if (!mars->process_lst[dest % PT_SIZE])
    {
        new_process->next = NULL;
        mars->process_lst[dest % PT_SIZE] = new_process;
    }
    else if (new_process->id > mars->process_lst[dest % PT_SIZE]->id)
    {
        new_process->next = mars->process_lst[dest % PT_SIZE];
        mars->process_lst[dest % PT_SIZE] = new_process;
    }
    else
    {
        
        tmp2 = mars->process_lst[dest % PT_SIZE];
        tmp = tmp2->next;
        while (tmp && new_process->id < tmp->id)
        {
            tmp2 = tmp;
            tmp = tmp->next;
        }
        tmp2->next = new_process;
        new_process->next = tmp;
     }
    return (new_process);
}

t_processus     *tab_get_next_process(t_mars *mars, int dest)
{
    t_processus *get;

    get = mars->process_lst[dest % PT_SIZE];
    if (!get)
        mars->process_lst[dest % PT_SIZE] = NULL;    
    else
        mars->process_lst[dest % PT_SIZE] = get->next;
    return(get);   
}

t_processus     *tab_see_process(t_mars *mars, int dest)
{
    t_processus *get;

    get = mars->process_lst[dest % PT_SIZE];
    return(get);   
}

t_processus    *move_process(t_mars *mars, int current_index, int dest)
{
    t_processus *moving;
    moving =  tab_get_next_process(mars, current_index);
    tab_set_process(mars, moving, dest);
	return (moving);
}
