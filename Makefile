# GENERAL
NAME1	:=	asm
NAME2	:=	corewar
CC		:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra
SRC_DIR :=	srcs
OBJ_DIR	:=	objs
INC_DIR	:=	includes
LIB_DIR	:=	lib

# LIB
LIB_FT_DIR	:=	$(LIB_DIR)/libft
LIB_PR_DIR	:= 	$(LIB_DIR)/ft_printf
LIBFT_A		:=	$(LIB_FT_DIR)/libft.a
PRINTF_A	:=	$(LIB_PR_DIR)/libftprintf.a
LIBFT		:=	-L$(LIB_FT_DIR) -lft
PRINTF		:=	-L$(LIB_PR_DIR) -lftprintf
NCURSES		:=  -lncurses

# ASM
ASM_SRC_DIR := $(SRC_DIR)/asm
ASM_OBJ_DIR := $(OBJ_DIR)/asm

## ASM - INCLUDES
ASM_INC_SRC	:=	$(INC_DIR)/asm.h 	\
				$(INC_DIR)/op.h		\
				$(LIB_FT_DIR)/$(INC_DIR)/libft.h
ASM_INCS	:=	-I $(ASM_INC_SRC)

## ASM - SOURCES
ASM_SRCS	:=	asm.c				\
				header.c 			\
				exit1.c	 			\
				exit2.c 			\
				add_op.c 			\
				option.c 			\
				read.c 				\
				compile.c 			\
				redux.c 			\
				lexer.c 			\
				ft_lex1.c 			\
				ft_lex2.c 			\
				op.c 				\
				parser.c 			\
				ft_parse1.c			\
				ft_parse2.c			\
				labels.c 			\
				free.c 				\
				bytecode.c 			\
				ft_atoi_base.c 		\
				write.c 			\
				convert_label_int.c \
				convert_label_short.c \
				verbose.c 			\
				decompile.c 		\
				decompile_tools1.c 	\
				decompile_tools2.c 	\
				tools1.c 			\
				tools2.c 			\
				tools3.c 			\
				init_bytecode.c 	\
				ft_parse_tools.c 	\
				header_tools.c

ASM_OBJS	:=	$(addprefix $(ASM_OBJ_DIR)/, $(ASM_SRCS:.c=.o))

# VM
VM_SRC_DIR	:=	$(SRC_DIR)/vm
VM_OBJ_DIR	:=	$(OBJ_DIR)/vm
VM_OPPDIR 	:=	opp
VM_S_G_DIR	:=	get_and_set
VM_NCUDIR 	:=	ncurses
VM_UTIDIR 	:=	utils

## VM - INCLUDES
VM_INC_SRC	:=	$(INC_DIR)/mars.h 	\
				$(INC_DIR)/visu.h	\
				$(INC_DIR)/op.h		\
VM_INCS	:=	-I $(VM_INC_SRC)

## VM - SOURCES
VM_SRCS		:=	mars.c 									\
		  		ft_set_mars.c 							\
		  		ft_add_processus_to_mars.c	 			\
		  		ft_prepare_mars_memory.c 				\
		  		ft_write_champ_on_memory.c	 			\
		  		ft_errors.c 							\
		  		ft_display_memory.c	 					\
				$(VM_S_G_DIR)/ft_registers.c			\
				$(VM_S_G_DIR)/get_and_load_mars_values.c \
				$(VM_S_G_DIR)/ft_parse_opc.c			\
				$(VM_S_G_DIR)/get_srcs.c 				\
				$(VM_OPPDIR)/ft_get_opcode.c			\
		  		$(VM_OPPDIR)/addition.c					\
		  		$(VM_OPPDIR)/aff.c 						\
		  		$(VM_OPPDIR)/and.c 						\
		  		$(VM_OPPDIR)/direct_load.c 				\
		  		$(VM_OPPDIR)/direct_store.c 			\
		  		$(VM_OPPDIR)/fork.c 					\
		  		$(VM_OPPDIR)/indirect_load.c 			\
		  		$(VM_OPPDIR)/indirect_store.c 			\
		  		$(VM_OPPDIR)/jump.c 					\
		  		$(VM_OPPDIR)/live.c 					\
		  		$(VM_OPPDIR)/long_direct_load.c 		\
		  		$(VM_OPPDIR)/long_fork.c 				\
		  		$(VM_OPPDIR)/long_indirect_load.c		\
		  		$(VM_OPPDIR)/or.c 						\
		  		$(VM_OPPDIR)/substraction.c 			\
		  		$(VM_OPPDIR)/xor.c 						\
		  		$(VM_NCUDIR)/ft_init_ncurse.c			\
		  		$(VM_NCUDIR)/ft_ncurses_display.c		\
		  		$(VM_NCUDIR)/ft_ncurses_print_intro.c	\
		  		$(VM_NCUDIR)/ft_ncurses_print_live.c	\
		  		$(VM_NCUDIR)/ft_ncurses_get_input.c		\
				$(VM_UTIDIR)/ft_print_usage.c			\
				$(VM_UTIDIR)/ft_verbose.c				\
				$(VM_UTIDIR)/ft_free.c					\
				$(VM_UTIDIR)/ft_get_mars_options.c		\
				loop_through_battle.c					\
				cycle_mars_handler.c					\
				ft_move_pc.c							\
				adressage.c								\
				tab_of_process_lst.c					\
				ft_stock.c							\
				ending_game.c

VM_OBJS		:=	$(addprefix $(VM_OBJ_DIR)/, $(VM_SRCS:.c=.o))

# TERMINAL COMMANDS
MK		:= make -C
MK_C	:= make clean -C
MK_FC	:= make fclean -C
RM		:= /bin/rm -rf
MD		:= mkdir -p

# COLORS
LOG_CLEAR		= \033[2K
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[32m
LOG_VIOLET		= \033[1;35m
LOG_CLIGNO		= \033[5m

.PHONY: all clean fclean re

all: $(LIB_DIR) $(NAME1) $(NAME2)

$(NAME1): $(LIBFT_A) $(ASM_OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@echo "$(LOG_GREEN)Asm has been created successfully !$(LOG_NOCOLOR)"


$(NAME2): $(LIBFT_A) $(PRINTF_A) $(VM_OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(PRINTF) $(NCURSES)
	@echo "$(LOG_GREEN)Corewar has been created successfully !$(LOG_NOCOLOR)"
	@cat resources/ASCII_COREWAR

$(LIB_DIR): $(LIBFT_A) $(PRINTF_A)


$(LIBFT_A):
	@$(MK) $(LIB_FT_DIR)

$(PRINTF_A):
	@$(MK) $(LIB_PR_DIR)


$(ASM_OBJ_DIR)/%.o: $(ASM_SRC_DIR)/%.c
	@$(MD) $(OBJ_DIR)
	@$(MD) $(ASM_OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_DIR)


$(VM_OBJ_DIR)/%.o: $(VM_SRC_DIR)/%.c
	@$(MD) $(VM_OBJ_DIR)/$(VM_OBJ_DIR)
	@$(MD) $(VM_OBJ_DIR)/$(VM_OPPDIR)
	@$(MD) $(VM_OBJ_DIR)/$(VM_NCUDIR)
	@$(MD) $(VM_OBJ_DIR)/$(VM_UTIDIR)
	@$(MD) $(VM_OBJ_DIR)/$(VM_S_G_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_DIR)


clean:
	@$(MK_C) $(LIB_FT_DIR)
	@$(MK_C) $(LIB_PR_DIR)
	@$(RM) $(OBJ_DIR)
	@echo "$(LOG_RED)Delete all Objects files ! $(LOG_NOCOLOR)"

fclean: clean
	@$(MK_FC) $(LIB_FT_DIR)
	@$(MK_FC) $(LIB_PR_DIR)
	@$(RM) $(NAME1)
	@$(RM) $(NAME2)
	@echo "$(LOG_RED)$(NAME1) and $(NAME2) has been deleted !$(LOG_NOCOLOR)"

re: fclean all
