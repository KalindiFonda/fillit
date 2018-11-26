
#make lib included in compulation.
all:
	gcc -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c -g -O0
	gcc main.o -I libft/includes -L libft/ -lft -g -O0

lib:
	make -C libft/ fclean && make -C libft/

libclean:
	make -C libft/ fclean

fclean:
	/bin/rm -f libft/libft.a

clean: fclean
	/bin/rm -f get_next_line.o main.o

re: clean all