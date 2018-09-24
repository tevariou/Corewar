#include "asm.h"

static void		set_ind(t_file *line, t_lex **tokens, int type, int id)
{
	t_lex	*list;

	if ((list = *tokens) == line->tokens)
		return ;
	else if (list->token == L_LABEL_STR
		|| list->token == L_NUM
		|| (list->token == L_OP
		&& list->next != line->tokens
		&& (list->next->token == L_LABEL_STR
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

	list = *tokens;
	if (list->token == L_DIRECT)
		list->arg_type = T_DIR;
	else
		list->arg_type = T_IND;
	list->arg_id = ++(line->n_args);
	*tokens = list->next;
	set_ind(line, tokens, list->arg_type, list->arg_id);
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
	}
	else if ((list->token == L_DIRECT
		&& list->next != line->tokens
		&& (list->next->token == L_LABEL_STR
		|| list->next->token == L_NUM))
		|| list->token == L_LABEL_STR
		|| list->token == L_NUM)
		is_dir(line, tokens);
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
