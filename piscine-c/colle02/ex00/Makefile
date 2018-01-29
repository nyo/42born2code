
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anyo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/20 11:00:33 by anyo              #+#    #+#              #
#    Updated: 2016/08/20 12:12:36 by anyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2
SRC =	ft_check_char.c ft_check_rect.c ft_check_size.c ft_height.c \
		ft_is_colle.c ft_keep_e.c ft_keep_s.c ft_print_sbracket.c \
		ft_wich_colle.c ft_width.c
MAIN = main.c
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(MAIN) $(SRC) -L. -lft -o $(NAME)

fclean:
	/bin/rm -f $(NAME)