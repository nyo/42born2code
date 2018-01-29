# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anyo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/22 12:26:13 by anyo              #+#    #+#              #
#    Updated: 2016/08/22 13:12:47 by anyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./srcs/ft_putchar.c \
	./srcs/ft_putstr.c \
	./srcs/ft_strcmp.c \
	./srcs/ft_strlen.c \
	./srcs/ft_swap.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	
	gcc $(FLAGS) -I ./includes -c $(SRC)
	ar rc libft.a *.o

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
