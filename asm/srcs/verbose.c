/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:15:15 by triou             #+#    #+#             */
/*   Updated: 2018/10/08 19:58:53 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			ft_put_uint(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar('0' + nb % 10);
}

static void			ft_put_hex(unsigned char nb)
{
	const char	*tab;

	tab = HEXA;
	if (nb >= 16)
		ft_put_hex(nb / 16);
	ft_putchar(tab[nb % 16]);
}

static void			ft_put_byte(void *n, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)n;
	while (len)
	{
		ft_putstr("0x");
		if (*p < 16)
			ft_putchar('0');
		ft_put_hex(*p++);
		if ((--len))
			ft_putchar(' ');
	}
}

static void			write_prog_size(t_asm *a)
{
	t_code			*list;
	t_code			*tail;
	unsigned int	size;

	list = a->output;
	tail = list->prev;
	size = 0;
	while (list != tail)
	{
		size += list->size;
		list = list->next;
	}
	size += list->size;
	ft_putstr("Program size : ");
	ft_put_uint(size);
	ft_putendl(" bytes");
}

static void			write_header(t_asm *a)
{
	write_prog_size(a);
	ft_putstr("Name : \"");
	ft_putstr(a->header.prog_name);
	ft_putendl("\"");
	ft_putstr("Comment : \"");
	ft_putstr(a->header.comment);
	ft_putendl("\"\n");
}

static void			put_code(t_code *list)
{
	int	i;

	ft_put_byte(&(list->op_code), sizeof(list->op_code));
	ft_putchar('\t');
	if (list->ocp)
		ft_put_byte(&(list->ocp), sizeof(list->ocp));
	ft_putchar('\t');
	i = 0;
	while (i < 3 && list->args_type[i])
	{
		if (list->args_type[i] == T_DIR && !dir_len(list->op_code))
			ft_put_byte(&(list->args[i].u32), sizeof(list->args[i].u32));
		else if (list->args_type[i] == T_REG)
		{
			ft_put_byte(&(list->args[i].u8), sizeof(list->args[i].u8));
			ft_putstr("               ");
		}
		else
		{
			ft_put_byte(&(list->args[i].u16), sizeof(list->args[i].u16));
			ft_putstr("          ");
		}
		if ((++i) < 3 && list->args_type[i])
			ft_putstr("\t");
	}
	ft_putchar('\n');
}

static void			put_file(t_code *list)
{
	t_lex	*tok;
	int		i;

	tok = list->orig->tokens;
	while (tok->token != L_INSTRUCT)
		tok = tok->next;
	ft_putstr(tok->val);
	ft_putchar('\t');
	if (list->ocp)
		ft_putstr("[PEB]");
	ft_putchar('\t');
	i = 0;
	while (i < 3 && list->args_type[i])
	{
		if (list->args_type[i] == T_DIR)
		{
			ft_putchar(DIRECT_CHAR);
			ft_putstr(list->values[i]);
		}
		else
			ft_putstr(list->values[i]);
		if ((++i) < 3 && list->args_type[i])
			ft_putstr("\t\t\t");
	}
	ft_putchar('\n');
}

static void			write_content(t_asm *a)
{
	t_code	*list;
	t_code	*tail;

	list = a->output;
	tail = list->prev;
	while (list != tail)
	{
		put_file(list);
		put_code(list);
		list = list->next;
		ft_putchar('\n');
	}
	put_file(list);
	put_code(list);
}

void	verbose_output(t_asm *a)
{
	ft_putendl(DUMPING_A);
	write_header(a);
	write_content(a);
}
