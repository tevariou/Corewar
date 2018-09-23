#include "asm.h"

static t_bool	p_lab(t_lex **list)
{
	
}

static t_bool	parse_line(t_file *line)
{
	t_lex	*list;

	list = line->tokens;
	if (p_lab(&list))
	{
		if (list != line->tokens && p_blanks(&list) && p_instruct(&list))
			return (TRUE);
		else if (list != line->tokens && p_instruct(&list))
			return (TRUE);
	}
	else if (p_instruct(&list))
		return (TRUE);
	return (FALSE);
}

void			parser(t_asm *a)
{
	t_file	*line;
	t_file	*tail;

	line = a->input;
	tail = line->prev;
	while (line != tail)
	{
		if (!parse_line(line))
			parse_error(a, line);
		line = line->next;
	}
	if (!parse_line(line))
		parse_error(a, line);
}
