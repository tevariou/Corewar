/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:22:07 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/18 19:15:34 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <locale.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# define BUFF_SIZE 2000
# define PTF_FLAG_ALL			(    0b111111111111)
# define PTF_TOGGLE_FLAG(x, flag)	(x ^= flag)
# define PTF_TURNON_FLAG(x, flag)	(x |= flag)

/*
 *** define flags on 1 integer
*/
# define PTF_FLAG_MINUS(x)		(x & 0b0000001)
# define PTF_FLAG_PLUS(x)		(x & 0b0000010)
# define PTF_FLAG_ZERO(x)		(x & 0b0000100)
# define PTF_FLAG_SPACE(x)		(x & 0b0001000)
# define PTF_FLAG_HASHTAG(x)	(x & 0b0010000)

/*
 *** define length modifier on 1 int
*/
# define PTF_LEN_H(x)		(x & 0b00000001)
# define PTF_LEN_HH(x)		(x & 0b00000010)
# define PTF_LEN_L(x)		(x & 0b00000100)
# define PTF_LEN_LL(x)		(x & 0b00001000)
# define PTF_LEN_J(x)		(x & 0b00010000)
# define PTF_LEN_Z(x)		(x & 0b00100000)
# define PTF_NO_PRE(x)		(x & 0b01000000)
# define FLAG argument->flag
# define WIDTH argument->width
# define PRECISION argument->precision
# define TYPE argument->type
# define VALUE argument->value

typedef struct	s_arg
{
	int			flags;
	int			l_modifier;
	int			is_negative;
	int			width;
	char		type;
	int			precision;
}				t_arg;

typedef struct	s_ptf_indexes
{
	int			i;
	int			k;
	char		*bufi;
}				t_ptf_indexes;

/*
 *** every functions needed
*/
int				ft_parse_arg(const char *format, t_arg *argument);
int				build_arg(char *buffer, t_arg *argument, uintmax_t *arg);
int				write_buffer(char **buffer, int src);
int				ft_printf(const char *format, ...);
int				ft_conv_char(char *buffer, t_arg *argument, char value);
int				ft_conv_wchar(char *buffer, t_arg *argument, int value);
int				ft_conv_string(char *buffer, t_arg *argument, char *value);
int				ft_conv_wstring(char *buffer, t_arg *argument, int *value);
int				ft_conv_octal(char *buffer, t_arg *argument, uintmax_t value);
int				ft_conv_integer(char *buffer, t_arg *argument, intmax_t value);
int				ft_conv_unsigned_integer(char *buffer, t_arg *argument,
		uintmax_t value);
int				ft_conv_hashtag(char *buffer, t_arg *argument);
int				ft_conv_hexa(char *buffer, t_arg *argument, uintmax_t value);
int				ft_conv_pointeur(char *buffer, t_arg *argument,
		uintmax_t value);
char			*wchartochar(int c, char **buffer);
int				ft_conv_uint(char *buffer, unsigned int arg);
int				ft_log_discret(unsigned int nb, int base);
int				ft_cast_itoa(intmax_t value, char *t, t_arg *arg, int base);
int				ft_cast_uitoa(uintmax_t value, char *t, t_arg *arg, int base);
int				check_limits(uintmax_t i, t_arg *arg, char *str);
int				stock_value(char **buffer, int value);
int				get_flag(const char *format, t_arg *argument);

/*
 *** extra funtions from libft to remove
 *** at some points
*/
int				ft_atoi(char const *str);
void			ft_bzero(void *s, size_t n);
char			*ft_itoa(intmax_t num, char *str, int base);
char			*ft_unsigned_itoa(uintmax_t num, char *str, int base, int size);
char			*ft_strcpy(char *dest, const char *src);
size_t			ft_strlen(const char *str);
#endif
