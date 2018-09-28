# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 08:57:44 by triou             #+#    #+#              #
#    Updated: 2018/09/28 15:09:37 by abiestro         ###   ########.fr        #

#                                                                              #
# **************************************************************************** #

NAME	= corewar
CC		= gcc
# CFLAGS	= -Wall -Werror -Wextra -pedantic $(debug)
CFLAGS	= -pedantic $(debug)
SDIR	= srcs
INC 	= ./libft/

IDIR	= includes
ODIR	= objs
OPPDIR  = opp
LDIR	= libft

ITEMS 	= 	mars.c 						\
		  	ft_set_mars.c 				\
		  	ft_add_processus_to_mars.c 	\
		  	ft_prepare_mars_memory.c 		\
		  	ft_write_champ_on_memory.c 	\
		  	ft_errors.c 					\
		  	ft_debug_display.c 			\
		  	ft_route_opp.c				\
		  	ft_registers.c				\
			ft_ocp.c				\
		  	$(OPPDIR)/addition.c			\
		  	$(OPPDIR)/aff.c 				\
		  	$(OPPDIR)/and.c 				\
		  	$(OPPDIR)/direct_load.c 		\
		  	$(OPPDIR)/direct_store.c 		\
		  	$(OPPDIR)/fork.c 				\
		  	$(OPPDIR)/indirect_load.c 	\
		  	$(OPPDIR)/indirect_store.c 	\
		  	$(OPPDIR)/jump.c 				\
		  	$(OPPDIR)/live.c 				\
		  	$(OPPDIR)/long_direct_load.c 	\
		  	$(OPPDIR)/long_fork.c 		\
		  	$(OPPDIR)/long_indirect_load.c \
		  	$(OPPDIR)/or.c 				\
		  	$(OPPDIR)/substraction.c 		\
		  	$(OPPDIR)/xor.c 				\


OBJS	= $(addprefix $(ODIR)/, $(ITEMS:.c=.o))

MD		= mkdir -p

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LDIR)
	@$(CC) $(CFLAGS) -o $(NAME) $^ -I $(IDIR) -I $(LDIR) -L $(LDIR) -lft
	@echo "success !!!!!!"
	
	
$(OBJS) : | $(ODIR)

$(ODIR):
	$(MD) $(ODIR)
	$(MD) $(ODIR)/opp

$(ODIR)/%.o : $(SDIR)/%.c $(INCLUDES)
	@$(MD) $(ODIR)/opp
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
