/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:04:54 by triou             #+#    #+#             */
/*   Updated: 2018/09/23 19:37:57 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft.h"

# define USAGE				"Usage:\t./asm [-a | -d] <sourcefile.s>\n\t-a : " \
							"Instead of creating a .cor file, outputs a " \
							"stripped and annotated version of the code " \
							"to the standard output\n\t-d : Translate a " \
							"binary file into assembly\n"
# define OPTION_STR_A		"-a"
# define OPTION_STR_D		"-d"
# define OPTION_A			1
# define OPTION_D			2
# define EXT				".s"
# define HEXA_MAJ			"0123456789ABCDEF"
# define HEXA_MIN			"0123456789abcdef"
# define INSTRUCT_NUMBER	16
# define FT_LEX_NUMBER		9

/* ERROR MESSAGES */
# define WRONG_EXT			"Wrong filename extension\n"
# define WRONG_HEADER		"Wrong header format\n"
# define FILE_OVERFLOW		"File is too big\n"
# define NAME_TOO_LONG		"Program name is too long\n"
# define COMMENT_TOO_LONG	"Program comment is too long\n"

typedef enum		e_tok {
	L_LAB = 1,
	L_REG,
	L_LABEL_STR,
	L_DIRECT,
	L_SEPARATOR,
	L_OP,
	L_NUM,
	L_INSTRUCT,
	L_BLANKS
}					t_tok;

typedef struct		s_ft_lex {
	char			*(*f)(char *);
	t_tok			token;
}					t_ft_lex;

typedef struct		s_lex {
	t_tok			token;
	int				arg_id;
	int				arg_type;
	char			*val;
	struct s_lex	*prev;
	struct s_lex	*next;
}					t_lex;

typedef struct		s_lab {
	char			*label;
	struct s_lab	*next;
}					t_lab;

typedef struct		s_arg {
	int				arg_id;
	int				arg_type;
	char			**tab;
}					t_arg;

typedef struct		s_file {
	size_t			n;
	char			*line;
	t_lab			*labels;
	char			*instruct;
	t_arg			args[3];
	int				n_args;
	t_lex			*tokens;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

typedef struct		s_asm {
	int				option;
	t_file			*input;
	header_t		header;
}					t_asm;

typedef				s_parse {
	char			*instruct[5];
	t_bool			(*f)(t_file *line, t_lex **token);
}					t_parse;

void				get_comment(t_asm *a, int fd, size_t *n);
void				get_name(t_asm *a, int fd, size_t *n);
void				err_free_exit(t_asm *a, const char *err);
void				ft_puterr(const char *err);
void				print_usage_exit(void);
void				add_input_line(t_asm *a, char **line, size_t n);
int					set_option(int ac, char **av);
void				get_file(t_asm *a, char *file);
void				compile_asm(t_asm *a, char *file);
void				header_error(t_asm *a, char *line);
void				lex_error(t_asm *a, t_file *line);

#endif
