# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 16:32:48 by bjasper           #+#    #+#              #
#    Updated: 2020/01/20 21:11:37 by bjasper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isdigit.c ft_putnbr.c	ft_strcmp.c ft_strlen.c ft_putstr.c ft_strcpy.c ft_strncpy.c ft_atoi.c	ft_putchar.c ft_strdup.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_striter.c ft_strmap.c ft_memcmp.c ft_memset.c ft_bzero.c ft_islower.c ft_isupper.c ft_isalpha.c ft_memchr.c ft_striteri.c ft_strmapi.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_isalnum.c ft_memcpy.c ft_memccpy.c ft_memdel.c ft_memmove.c ft_strjoin.c ft_strequ.c ft_strnequ.c ft_putendl.c ft_putendl_fd.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_isprint.c ft_isascii.c ft_strdel.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strclr.c ft_itoa.c ft_nbrlen.c ft_strnew.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strsub.c ft_strtrim.c ft_strlento.c ft_skip_sym.c ft_strlento.c ft_massmalloc.c ft_strccpy.c ft_strsplit.c get_next_line.c
FLAG = -Wall -Wextra -Werror
H_LIBFT	= libft.h
OS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	gcc $(FLAG) -c $< -o $@

$(NAME): $(OS)
	ar rc $(NAME) $(OS)
	ranlib $(NAME)
	
clean:
	rm -rf $(OS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
