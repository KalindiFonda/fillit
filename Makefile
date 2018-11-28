
# TODO make lib included in compulation.
NAME = fillit
SRC = main.c algo.c print.c helper.c map.c tetri.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

HEADER = -I libft/
LIB = -L libft/ -lft

all: $(NAME)

$(NAME):
	gcc $(FLAGS)  $(HEADER) -c $(SRC) -g
	gcc $(OBJ) $(HEADER) $(LIB) -g -o $(NAME)

lib: libclean
	make -C libft/ && make -C libft/ clean

libclean:
	make -C libft/ fclean

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
