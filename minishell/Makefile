CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -I$(HOME)/.brew/Cellar/readline/8.1.2/include #-fsanitize=address -fno-omit-frame-pointer

NAME = minishell

SRC = minishell.c\
		code_char.c\
		free.c\
		malloc.c\
		minishell_utils.c\
		signals.c\
		split_modif.c\
		one.c\
		get_path.c\
		quotes.c\
		redirections.c\
		dollar.c\
		error.c
	
YELLOW=$'\x1b[33m
RED=$'\x1b[31m

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	make -C libft
#	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -lreadline -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -lreadline  -L$(HOME)/.brew/Cellar/readline/8.1.2/lib -o $(NAME)
#	$(CC) $(CFLAGS) $(OBJ) -libft/libft.a -lreadline -L$(HOME)/.brew/opt/readline/lib -I$(HOME)/.brew/opt/readline/include
	@echo "${YELLOW}The best MiniShell ever is compiled"


clean:
	make clean -C libft
	rm -f $(OBJ)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)
	@echo "${RED}SUCCESS"

re : fclean all

.PHONY: all clean fclean re