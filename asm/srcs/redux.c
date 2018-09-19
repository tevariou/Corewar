#include "asm.h"

void	redux(t_asm *a)
{
	t_file	*list;
	t_file	*tail;

	list = a->input;
	tail = list->prev;
	while (list != tail)
	{
		list = list->next;	
	}
}
