# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: triou <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 08:57:44 by triou             #+#    #+#              #
#    Updated: 2018/10/10 11:59:22 by triou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -fsanitize=address -Wall -Werror -Wextra
NAME = asm
SDIR = srcs
IDIR = includes
ODIR = objs
LDIR = ../libft
SRCS =	asm.c \
		comment.c \
		exit1.c \
		exit2.c \
		name.c \
		add_op.c \
		option.c \
		read.c \
		compile.c \
		redux.c \
		lexer.c \
		ft_lex1.c \
		ft_lex2.c \
		op.c \
		parser.c \
		ft_parse1.c \
		ft_parse2.c \
		labels.c \
		free.c \
		bytecode.c \
		ft_atoi_base.c \
		write.c \
		convert_label_int.c \
		convert_label_short.c \
		verbose.c \
		decompile.c \
		decompile_tools1.c \
		decompile_tools2.c \
		tools1.c \
		tools2.c \
		tools3.c \
		init_bytecode.c \
		ft_parse_tools.c
LIB = ft
_INCLUDES = op.h asm.h
INClUDES = $(patsubst %, $(IDIR)/%, $(_INCLUDES))
_OBJ = $(SRCS:.c=.o)
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LDIR)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LDIR) -l$(LIB)
	@echo "\033[1;34masm \033[1;35mhas been created \033[1;5;32msuccessfully.\033[0m"

$(ODIR)/%.o : $(SDIR)/%.c $(INCLUDES)
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(IDIR) -I$(LDIR)

clean :
	@$(MAKE) -C $(LDIR) clean
	@rm -rf $(ODIR)

fclean : clean
	@$(MAKE) -C $(LDIR) fclean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
