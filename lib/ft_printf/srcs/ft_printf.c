/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:48:13 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/08 23:53:55 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				write_buffer(char **buffer, int src)
{
	static int	buff_delimitor = 0;
	static char *s = 0;
	int			returned;

	if (buffer && ++buff_delimitor)
	{
		if (s == 0)
			s = *buffer;
		**buffer = src;
		if (buff_delimitor != 0 && buff_delimitor % BUFF_SIZE == 0)
		{
			*buffer = s;
			write(1, *buffer, BUFF_SIZE);
		}
		else
			++*buffer;
	}
	else
	{
		returned = buff_delimitor;
		if (src == '0')
			buff_delimitor = 0;
		return (returned);
	}
	return (buff_delimitor);
}

static int		add_nomodifier(char **bufi, t_arg *argument)
{
	int i;

	i = 1;
	if (argument->flags)
		i++;
	if (argument->width > 0)
	{
		i += ft_log_discret(argument->width, 10) + 1;
		while (--argument->width > 0)
		{
			if (PTF_FLAG_ZERO(argument->flags))
				write_buffer(bufi, '0');
			else
				write_buffer(bufi, ' ');
		}
		if (!PTF_NO_PRE(argument->l_modifier))
			i++;
	}
	return (i);
}

static int		inside_the_loop(const char *format,
		t_ptf_indexes *index, va_list argl)
{
	t_arg	argument;
	int		retour;

	if (*format != '%')
	{
		retour = (1);
		write_buffer(&index->bufi, *format++);
	}
	else
	{
		index->i = ft_parse_arg(format, &argument);
		if (argument.type == 0)
			retour = (add_nomodifier(&index->bufi, &argument));
		else
		{
			if (argument.type == '%')
				build_arg(index->bufi, &argument, 0);
			else if (build_arg(index->bufi, &argument, va_arg(argl, void*)) < 0)
				return (-1);
			index->k = 0;
			retour = (index->i);
		}
	}
	return (retour);
}

int				ft_printf(const char *format, ...)
{
	va_list			argl;
	char			buffer[BUFF_SIZE];
	t_ptf_indexes	index;
	int				i;

	ft_bzero(&index, 3);
	ft_bzero(&buffer, BUFF_SIZE);
	va_start(argl, format);
	while (*format && ++index.k)
	{
		index.bufi = &buffer[write_buffer(NULL, 0) % BUFF_SIZE];
		i = inside_the_loop(format, &index, argl);
		if (i == -1)
		{
			write(1, buffer, write_buffer(NULL, '0') - index.k + 1);
			return (-1);
		}
		else
			format = &format[i];
	}
	va_end(argl);
	write(1, buffer, write_buffer(NULL, 0) % BUFF_SIZE);
	return (write_buffer(NULL, '0'));
}
