#include "asm.h"

static void		set_ind(t_file *line, t_lex **tokens, int type, int id)
{
	t_lex	*list;

	list = *tokens;
	if (list->token == LABEL_STR
		|| list->token == L_NUM
		|| (list->token == L_OP
		&& list->next != line->tokens
		&& (list->next->token == LABEL_STR
		|| list->next->token == L_NUM)))
	{
		list->arg_type = type;
		list->arg_id = id;
		*tokens = list->next;	
	}
	else
		return ;
	set_ind(line, tokens, type, id);
}

static void		is_dir(t_file *line, t_lex **tokens)
{
	t_lex	*list;
	int		type;
	int		id;

	list = *tokens;
	id = ++(line->n_args);
	if (list->token == L_DIRECT)
	{
		type = T_DIR;
		list->arg_type = type;
		list->arg_id = id;
		*tokens = list->next;
	}
	else
		type = T_IND;
	set_ind(line, tokens, id, type);
}

static void		set_arg(t_file *line, t_lex **tokens)
{
	t_lex	*list;

	list = *tokens;
	list->arg_id = 0;
	list->arg_type = 0;
	if (list->token == L_LAB)
		list->arg_type = T_LAB;
	else if (list->token == L_REG)
	{
		list->arg_type = T_REG;
		list->arg_id = ++(line->n_args);
	}
	else if ((list->token == L_DIRECT
		&& list->next != line->tokens
		&& (list->next->token == L_LABEL_STR
		|| list->next->token == L_NUM))
		|| list->token == L_LABEL_STR
		|| list->token == L_NUM)
		is_dir(line, tokens);
}

static void		parse_tokens(t_file *line)
{
	t_lex	*list;
	t_lex	*tail;

	list = line->tokens;
	tail = list->prev;
	list->n_args = 0;
	while (list != tail)
	{
		set_arg(line, &list);
		list = list->next;
	}
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
	args_cat(list);
}
