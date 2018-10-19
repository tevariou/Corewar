# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiestro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/01 13:01:09 by abiestro          #+#    #+#              #
#    Updated: 2018/10/19 14:11:54 by abiestro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

PATH_INCLUDES	= ./includes
PATH_SOURCES	= ./srcs
PATH_OBJS		= ./objs

INCLUDES		= ft_printf.h 

ITEMS			= ft_printf \
				  parse_struct \
				  parse_struct2 \
				  ft_setarg \
				  arg_char \
				  arg_wchar \
				  arg_octal \
				  arg_hexa \
				  arg_hashtag \
				  arg_string \
				  arg_wstring \
				  arg_pointeur \
				  arg_int \
				  arg_unsigned_int \
				  utils_math \

LIB_NEEDED		= ft_atoi \
				  ft_bzero \
				  ft_strcpy \
				  ft_strlen \
				  ft_itoa \

OBJS			= $(addprefix $(PATH_OBJS)/, $(ITEMS:=.o))
OBJS			+= $(addprefix $(PATH_OBJS)/, $(LIB_NEEDED:=.o))
INCLUDES		= $(addprefix $(PATH_INCLUDES)/, ft_printf.h)

.PHONY : all clean fclean re
all:$(NAME)

$(NAME):$(OBJS)
		@ar -rcs $(NAME) $(OBJS) $(OBJS_EXTRA)
		@echo $(NAME) "ready!"

$(OBJS) : |$(PATH_OBJS)

$(PATH_OBJS) :
	@mkdir objs

$(PATH_OBJS)/%.o : $(PATH_SOURCES)/%.c
	@$(CC) -c $(CFLAGS)  $<  -o $@

clean:
		@rm -rf $(PATH_OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

