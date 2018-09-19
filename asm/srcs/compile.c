#include "asm.h"

void	compile_asm(t_asm *a, char *file)
{
	get_file(a, file);
	lexer(a);
	redux(a);
}
