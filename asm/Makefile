# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: triou <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 08:57:44 by triou             #+#    #+#              #
#    Updated: 2018/09/08 16:31:09 by triou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -fsanitize=address -Wall -Werror -Wextra
NAME = asm
SDIR = srcs
IDIR = includes
ODIR = objs
LDIR = libft
SRCS =	asm.c \
		op.c
LIB = ft
_INCLUDES = op.h
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
