
#make lib included in compulation.
NAME = fillit
SRC = main.c algo.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I libft/includes -c $(SRC) -g -O0
	gcc $(OBJ) -I libft/includes -L libft/ -lft -g -O0 -o $(NAME)

lib:
	make -C libft/ fclean && make -C libft/

libclean:
	make -C libft/ fclean

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all