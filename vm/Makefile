# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiestro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 08:57:44 by triou             #+#    #+#              #
#    Updated: 2018/09/28 15:09:37 by abiestro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= corewar
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -pedantic $(debug)
SDIR	= srcs
INC 	= ./libft/

IDIR	= includes
ODIR	= objs
LDIR	= libft

ITEMS 	= mars.c \
		  ft_set_mars.c \
		  ft_add_processus_to_mars.c \
		  ft_prepare_mars_memory.c \
		  ft_write_champ_on_memory.c \
		  ft_errors.c \
		  ft_debug_display.c \
		  ft_registers.c

OBJS	= $(addprefix $(ODIR)/, $(ITEMS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LDIR)
	@$(CC) $(CFLAGS) -o $(NAME) $^ -I $(IDIR) -I $(LDIR) -L $(LDIR) -lft
	@echo "success !!!!!!"
	
	
$(OBJS) : | $(ODIR)

$(ODIR):
	mkdir $(ODIR)

$(ODIR)/%.o : $(SDIR)/%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(IDIR) -I $(LDIR)
	@echo "compiling $<"

clean :
	@$(MAKE) -C $(LDIR) clean
	@rm -rf $(ODIR)

fclean : clean
	@$(MAKE) -C $(LDIR) fclean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
