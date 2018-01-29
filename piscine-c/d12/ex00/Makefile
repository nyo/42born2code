# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anyo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/23 18:19:50 by anyo              #+#    #+#              #
#    Updated: 2016/08/23 18:25:20 by anyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = main.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -L. -lft -o $(NAME)

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -f $(NAME)
