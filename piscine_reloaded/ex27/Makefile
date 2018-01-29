# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anyo                                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 12:57:55 by anyo              #+#    #+#              #
#    Updated: 2016/11/03 13:10:47 by anyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

CC = gcc -Wall -Wextra -Werror

SOURCES_C = ./main.c

all: $(NAME)

$(NAME):
	$(CC) $(SOURCES_C) -L. -lft -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
