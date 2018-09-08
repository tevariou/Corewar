CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SDIR = .
IDIR = .
ODIR = .
SRCS =	ft_memset.c \
		ft_memcpy.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strndup.c \
		ft_strcpy.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strnew.c \
		ft_strequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_isdigit.c \
		ft_isspace.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_strclr.c \
		ft_strsplit.c \
		ft_putendl.c \
		ft_binsearch.c \
		ft_bzero.c \
		ft_strncmp.c \
		ft_strnequ.c \
		ft_strsplit.c \
		ft_strtrim.c
_INCLUDES = libft.h
INClUDES = $(patsubst %, $(IDIR)/%, $(_INCLUDES))
_OBJ = $(SRCS:.c=.o)
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

all : $(NAME)

$(NAME) : $(OBJ)
	@ar crs $@ $^
	@echo "\033[1;34mLibft \033[1;35mhas been created \033[1;5;32msuccessfully.\033[0m"
	
$(ODIR)/%.o : $(SDIR)/%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(IDIR)

clean : 
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
