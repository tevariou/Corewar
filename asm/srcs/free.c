#include "asm.h"
#include <stdlib.h>

void	free_tokens(t_lex *l)
{
	t_lex	*head;
	t_lex	*tail;
	t_lex	*tmp;

	if (!(head = l->tokens))
		return ;
	tail = l->tokens->prev;
	while (head != tail)
	{
		tmp = head;
		head = head->next;
		free(tmp->val);
		free(tmp);
	}
	free(head->val);
	free(head);
	l->tokens = NULL;
}

void	free_input(t_asm *a)
{
	t_file	*head;
	t_file	*tail;
	t_file	*tmp;

	if (!(head = a->input))
		return ;
	tail = a->input->prev;
	while (head != tail)
	{
		tmp = head;
		head = head->next;
		free(tmp->line);
		free(tmp);
	}
	free(head->line);
	free(head);
	a->input = NULL;
}

