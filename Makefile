# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 14:14:45 by bjasper           #+#    #+#              #
#    Updated: 2020/03/10 20:45:05 by bjasper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC =	src/main.c\
		src/parser.c\
		src/liba.c\
		src/parse_edges.c\
		src/parse_rooms.c\
		src/parsers_utilits.c\
		src/ft_solution.c\
		src/equal_rooms.c\
		src/bfs.c\
		src/recorder_way.c\
		src/movements.c\
		src/instruments.c\

INCL = includes/lem_in.h 

GCC_FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C src/libft
	gcc -o $(NAME) $(OBJ)  -lft -L./src/libft
	
%.o: %.c $(INCL)
	gcc -I $(INCL) $< -c -o $@
	
clean:
	rm -rf $(OBJ)
	make clean -C src/libft/

fclean: clean
	rm -rf $(NAME)

re: fclean all
