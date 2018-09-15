/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:04:54 by triou             #+#    #+#             */
/*   Updated: 2018/09/15 18:03:13 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"

# define USAGE "Usage:\t./asm [-a] <sourcefile.s>\n\t-a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output\n"
# define OPTION "-a"
# define EXT ".s"
# define QUOTE_CHAR '"'

/* ERROR MESSAGES */
# define WRONT_EXT "Wrong filename extension\n"
# define FILE_OVERFLOW "File is too big\n"

typedef struct		s_file {
	size_t			n;
	char			*line;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

typedef struct		s_asm {
	t_bool			option;
	t_file			*input;
	header_t		header;
}					t_asm;

#endif
