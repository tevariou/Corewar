/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:04:54 by triou             #+#    #+#             */
/*   Updated: 2018/09/17 20:33:55 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft.h"

# define USAGE				"Usage:\t./asm [-a] <sourcefile.s>\n\t-a : Instead of " \
							"creating a .cor file, outputs a stripped and annotated " \
							"version of the code to the standard output\n"
# define OPTION				"-a"
# define EXT				".s"

# define L_STR_LABEL		1
# define L_LABEL_STR		2
# define L_DIRECT			3
# define L_SEPARATOR		4
# define L_REG				5
# define L_OP				6
# define L_NUM				7
# define L_BLANKS			8

/* ERROR MESSAGES */
# define WRONG_EXT			"Wrong filename extension\n"
# define FILE_OVERFLOW		"File is too big\n"
# define NAME_TOO_LONG		"Program name is too long\n"
# define COMMENT_TOO_LONG	"Program comment is too long\n"



typedef struct		s_lex {
	t_tok			tok;
}					t_lex;

typedef struct		s_file {
	size_t			n;
	char			*line;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

typedef struct		s_asm {
	t_bool			option;
	t_file			*input;
	t_lex			*lex;
	header_t		header;
}					t_asm;

void				get_comment(t_asm *a, int fd, size_t *n);
void				get_name(t_asm *a, int fd, size_t *n);
void				parse_error(t_asm *a, char *line, size_t n);
void				err_free_exit(t_asm *a, const char *err);
void				ft_puterr(const char *err);
void				print_usage_exit(void);
void				add_input_line(t_asm *a, char **line, size_t n);
t_bool				set_option(int ac, char **av);
void				get_file(t_asm *a, char *file);

#endif
