#include "asm.h"

static void		is_dir_ind(t_file *line, t_lex **tokens)
{
	t_lex	*list;
	int		id;

	list = *tokens;
	id = ++(line->n_args);
	if (list->token == L_DIRECT)
	{
		list->arg_type = T_DIR;
		list->arg_id = id;
		list->next->arg_type = T_DIR;
		list->next->arg_id = id;
		*tokens = list->next->next;
		return ;
	}
	list->arg_type = T_IND;
	list->arg_id = id;
	*tokens = list->next;	
}

static void		set_arg(t_file *line, t_lex **tokens)
{
	t_lex	*list;

	list = *tokens;
	list->arg_id = 0;
	list->arg_type = 0;
	if (list->token == L_REG)
	{
		list->arg_type = T_REG;
		list->arg_id = ++(line->n_args);
		*tokens = list->next;
	}
	else if ((list->token == L_DIRECT
		&& list->next != line->tokens
		&& (list->next->token == L_LABEL_STR
		|| list->next->token == L_NUM))
		|| list->token == L_LABEL_STR
		|| list->token == L_NUM)
		is_dir_ind(line, tokens);
	else
		*tokens = list->next;
}

static void		parse_tokens(t_file *line)
{
	t_lex	*list;

	list = line->tokens;
	line->n_args = 0;
	set_arg(line, &list);
	while (list != line->tokens)
		set_arg(line, &list);
}

void			redux(t_asm *a)
{
	t_file	*list;
	t_file	*tail;

	list = a->input;
	tail = list->prev;
	while (list != tail)
	{
		parse_tokens(list);
		list = list->next;	
	}
	parse_tokens(list);
}
