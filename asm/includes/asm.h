/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:04:54 by triou             #+#    #+#             */
/*   Updated: 2018/10/09 21:38:31 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft.h"

# define WRITING_FILE		"Writing output program to "
# define DUMPING_A			"Dumping annotated program on standard output"
# define DUMPING_D			"Writing output source file to "
# define OPTION_STR_A		"-a"
# define OPTION_STR_D		"-d"
# define OPTION_A			1
# define OPTION_D			2
# define EXT				".s"
# define EXT_COMP			".cor"
# define HEXA				"0123456789ABCDEF"
# define DEC				"0123456789"
# define FT_LEX_NUMBER		8
# define WRONG_EXT			"Invalid filename"
# define WRONG_HEADER		"Wrong header format"
# define NAME_TOO_LONG		"Program name is too long"
# define COMMENT_TOO_LONG	"Program comment is too long"
# define NO_INSTRUCTION		"No instruction"
# define WRONG_REG_NUMBER	"Wrong registry number at line "
# define UNKNOWN_LABEL		"Unknown label found at line "
# define INVALID_ARGS		"Invalid arguments at line "
# define LEXER_ERROR		"Lexical error at line "
# define PARSER_ERROR		"Parser error at line "
# define FILE_OVERFLOW		"File is too big"

typedef enum			e_tok {
	L_LAB = 1,
	L_REG,
	L_LABEL_STR,
	L_DIRECT,
	L_SEPARATOR,
	L_OP,
	L_NUM,
	L_INSTRUCT,
	L_BLANKS
}						t_tok;

typedef struct			s_ft_lex {
	char				*(*f)(char *);
	t_tok				token;
}						t_ft_lex;

typedef struct			s_lex {
	t_tok				token;
	int					arg_type;
	char				*val;
	struct s_lex		*prev;
	struct s_lex		*next;
}						t_lex;

typedef struct			s_file {
	unsigned int		n;
	char				*line;
	int					n_args;
	t_lex				*tokens;
	struct s_file		*prev;
	struct s_file		*next;
}						t_file;

typedef struct			s_parse {
	char				*name[5];
	t_bool				(*f)(t_file *line, t_lex **token);
	int					n_args;
}						t_parse;

typedef struct			s_label {
	char				*name;
	t_file				*target;
	struct s_label		*prev;
	struct s_label		*next;
}						t_label;

typedef union			u_arg {
	unsigned int		u32;
	unsigned short		u16;
	unsigned char		u8;
}						t_arg;

typedef struct			s_code {
	t_byte				op_code;
	t_byte				ocp;
	int					args_type[3];
	char				*values[3];
	t_arg				args[3];
	unsigned int		size;
	t_file				*orig;
	struct s_code		*prev;
	struct s_code		*next;
}						t_code;

typedef struct			s_asm {
	int					option;
	t_file				*input;
	t_label				*labels;
	t_code				*output;
	t_header			header;
}						t_asm;

char					*get_quote(t_asm *a, int fd, unsigned int *n, char *line);
void					get_comment(t_asm *a, int fd, unsigned int *n);
void					get_name(t_asm *a, int fd, unsigned int *n);

void					print_usage_exit(void);
void					init_bytecode(t_asm *a);
int						set_option(int ac, char **av);
void					get_file(t_asm *a, char *file);
void					compile_asm(t_asm *a, char *file);

void					header_error(t_asm *a, char *line);
void					asm_error(t_asm *a, t_file *line,
									char *str, const char *err);
void					parser_error(t_asm *a, t_file *line, const char *err);
void					err_free_exit(t_asm *a, const char *err);

void					lexer(t_asm *a);
void					redux(t_asm *a);
void					parser(t_asm *a);
void					get_labels(t_asm *a);
void					free_all(t_asm *a);
t_bool					dir_len(t_byte op_code);
void					write_bytecode(t_asm *a, char *file);
void					set_bytecode(t_asm *a);

unsigned short			convert_label_short(t_asm *a, t_code *op, char *str);
unsigned int			convert_label_int(t_asm *a, t_code *op, char *str);

unsigned int			atoi_base_int(char *str, char *base);
unsigned short			atoi_base_short(char *str, char *base);
unsigned char			atoi_reg(t_asm *a, t_code *op, char *str);
void					reverse_bytes(void *n, size_t size);

void					check_extension(char *file, const char *ext);
char					*set_extension(t_asm *a, char *file,
										const char *dest, const char *src);

void					verbose_output(t_asm *a);
void					decompile_bin(char *file);
void					decompile_error(char **out);

void					add_t_reg(t_code *new, int index, t_bool ocp);
void					add_t_dir(t_code *new, int index, t_bool ocp);
void					add_t_ind(t_code *new, int index, t_bool ocp);

t_bool					ft_tabequ(char *tab[5], char *needle);
void					ft_put_byte(void *n, size_t len);
void					ft_put_uint(unsigned int nb);
char					*skip_space(char *line);

void					ft_buffer(char **out, char *new);
void					put_reg(int n, char **out, t_bool end);
void					put_ind(int n, char **out, t_bool end);
void					put_dir(int n, char **out, t_bool end, t_bool len);

void					read_magic(int in);
void					read_name(int in, char **out);
void					read_comment(int in, char **out);
void					read_content(int in, char **out);

t_lex					*traverse_arg(t_file *line, t_lex *list, int type);
t_lex					*is_dir_ind_reg(t_file *line, t_lex *list);
t_lex					*is_dir_reg(t_file *line, t_lex *list);
t_lex					*is_ind_reg(t_file *line, t_lex *list);

char					*ft_str_label(char *str);
char					*ft_label_str(char *str);
char					*ft_direct(char *str);
char					*ft_separator(char *str);
char					*ft_reg(char *str);
char					*ft_op(char *str);
char					*ft_number(char *str);
char					*ft_instruct(char *str);
char					*ft_blanks(char *str);

t_bool					ft_parse_0(t_file *line, t_lex **token);
t_bool					ft_parse_1(t_file *line, t_lex **token);
t_bool					ft_parse_2(t_file *line, t_lex **token);
t_bool					ft_parse_3(t_file *line, t_lex **token);
t_bool					ft_parse_4(t_file *line, t_lex **token);
t_bool					ft_parse_5(t_file *line, t_lex **token);
t_bool					ft_parse_6(t_file *line, t_lex **token);
t_bool					ft_parse_7(t_file *line, t_lex **token);

#endif
