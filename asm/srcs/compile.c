/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:57:17 by triou             #+#    #+#             */
/*   Updated: 2018/10/08 16:33:50 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	compile_asm(t_asm *a, char *file)
{
	get_file(a, file);
	lexer(a);
	redux(a);
	parser(a);
	get_labels(a);
	set_bytecode(a);
	if (!(a->option))
		write_bytecode(a, file);
	else
		verbose_output(a);
}
