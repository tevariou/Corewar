#include "asm.h"

static t_bool	p_lab(t_asm *a, t_file *line)
{

}

static void		parse_line(t_asm *a, t_file *line)
{
	if (!p_lab(a, line) && !p_instruct(a, line))
		parse_error(a, line);
}

void			parser(t_asm *a)
{
	t_file	*line;
	t_file	*tail;

	line = a->input;
	tail = line->prev;
	while (line != tail)
	{
		parse_line(a, line);
		line = line->next;
	}
	parse_line(a, line);
}
