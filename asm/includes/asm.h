/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:04:54 by triou             #+#    #+#             */
/*   Updated: 2018/09/28 18:49:45 by triou            ###   ########.fr       */
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
# define HEXA				"0123456789ABCDEF"
# define FT_LEX_NUMBER		8

/* ERROR MESSAGES */
# define WRONG_EXT			"Wrong filename extension\n"
# define WRONG_HEADER		"Wrong header format\n"
# define FILE_OVERFLOW		"File is too big\n"
# define NAME_TOO_LONG		"Program name is too long\n"
# define COMMENT_TOO_LONG	"Program comment is too long\n"
# define NO_INSTRUCTION		"No instruction\n"

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

typedef struct		s_file {
	size_t			n;
	char			*line;
	int				n_args;
	t_lex			*tokens;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

typedef struct		s_parse {
	char			*instruct[5];
	t_bool			(*f)(t_file *line, t_lex **token);
	int				n_args;
}					t_parse;

typedef struct		s_label {
	char			*name;
	size_t			target;
	struct s_label	*prev;
	struct s_label	*next;
}					t_label;

typedef struct		s_asm {
	int				option;
	t_file			*input;
	t_label			*labels;
	header_t		header;
}					t_asm;

void				get_comment(t_asm *a, int fd, size_t *n);
void				get_name(t_asm *a, int fd, size_t *n);
void				err_free_exit(t_asm *a, const char *err);
void				print_usage_exit(void);
void				add_input_line(t_asm *a, char **line, size_t n);
void				add_token(t_asm *a, t_file *line, t_tok token, char *val);
int					set_option(int ac, char **av);
void				get_file(t_asm *a, char *file);
void				compile_asm(t_asm *a, char *file);
void				header_error(t_asm *a, char *line);
void				lex_error(t_asm *a, t_file *line, char *val);
void				parser_error(t_asm *a, t_file *line, char *val);
void				lexer(t_asm *a);
void				redux(t_asm *a);
void				parser(t_asm *a);
void				get_labels(t_asm *a);
void				free_input(t_asm *a);
void				n_arg_error(t_asm *a, t_file *line);

char				*ft_str_label(char *str);
char				*ft_label_str(char *str);
char				*ft_direct(char *str);
char				*ft_separator(char *str);
char				*ft_reg(char *str);
char				*ft_op(char *str);
char				*ft_number(char *str);
char				*ft_instruct(char *str);
char				*ft_blanks(char *str);

t_bool				ft_parse_0(t_file *line, t_lex **token);
t_bool				ft_parse_1(t_file *line, t_lex **token);
t_bool				ft_parse_2(t_file *line, t_lex **token);
t_bool				ft_parse_3(t_file *line, t_lex **token);
t_bool				ft_parse_4(t_file *line, t_lex **token);
t_bool				ft_parse_5(t_file *line, t_lex **token);
t_bool				ft_parse_6(t_file *line, t_lex **token);
t_bool				ft_parse_7(t_file *line, t_lex **token);

#endif
