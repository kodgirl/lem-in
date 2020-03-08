# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 14:14:45 by bjasper           #+#    #+#              #
#    Updated: 2020/03/08 15:23:55 by bjasper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC =	src/main.c\
		src/parser.c\
		src/delete.c\
		src/liba.c\
		src/parse_edges.c\
		src/parse_rooms.c

INCL = includes/lem_in.h 

GCC_FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C src/libft
	gcc -o $(NAME) $(OBJ) -L./src/libft -lft
	
%.o: %.c ${INCL}
	gcc -I $(INCL) $< -c -o $@
	
clean:
	rm -rf $(OBJ)
	make clean -C src/libft/

fclean: clean
	rm -rf $(NAME)

re: fclean all
