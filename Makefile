.PHONY: all clean fclean re
NAME = fillit

SRC =  main.c \
        fill_figure.c \
        fillit.c  \
        valid_tetramino.c \
        valid_help.c \
        lst_func.c \
        mtx_help.c \
        recursion.c 


SRO = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make re -C libft
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc $(SRO) -Llibft -lft -o $(NAME)

clean:
	/bin/rm -f $(SRO)
	make clean -C libft

fclean: clean
	/bin/rm -rf $(NAME) libft/libft.a

re: fclean all