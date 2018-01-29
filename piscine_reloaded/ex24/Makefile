# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anyo                                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 12:37:17 by anyo              #+#    #+#              #
#    Updated: 2016/11/03 12:49:14 by anyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -Wall -Wextra -Werror

SOURCES_C = ./srcs/ft_putchar.c \
			./srcs/ft_putstr.c \
			./srcs/ft_strcmp.c \
			./srcs/ft_strlen.c \
			./srcs/ft_swap.c

SOURCES_O = ./ft_putchar.o \
			./ft_putstr.o \
			./ft_strcmp.o \
			./ft_strlen.o \
			./ft_swap.o

all: $(NAME)

$(NAME):
	$(CC) -I ./includes -c $(SOURCES_C)
	ar rc $(NAME) $(SOURCES_O)

clean:
	/bin/rm -f $(SOURCES_O)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
