# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skunz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 22:31:10 by skunz             #+#    #+#              #
#    Updated: 2018/11/28 22:31:14 by skunz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c algo.c print.c map.c tetri.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

HEADER = -I libft/
LIB = -L libft/ -lft

all: $(NAME)

$(NAME): lib
	gcc $(FLAGS)  $(HEADER) -c $(SRC) -g
	gcc $(OBJ) $(HEADER) $(LIB) -g -o $(NAME)

lib:
	make -C libft/ all

libfclean:
	make -C libft/ fclean

libclean:
	make -C libft/ clean

clean: libclean
	/bin/rm -f $(OBJ)

fclean: clean libfclean
	/bin/rm -f $(NAME)

re: fclean all
