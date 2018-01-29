# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bin0me                                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 15:51:50 by bin0me            #+#    #+#              #
#    Updated: 2016/12/06 16:01:03 by anyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 
CC = gcc
WFLAGS = -Wall -Werror -Wextra
SRCS = srcs/
HEADERS = include/
LIBFT = libft/
LIB = libft/libft.a
OBJ_PATH = obj/
FILES = main			\
		solve			\
		ft_sqrt			\
		trim_str		\
		init_map		\
		get_piece		\
		check_file		\
		file_to_str		\
		print_solution
CFILES = $(addprefix $(SRCS), $(addsuffix .c, $(FILES)))
OFILES = $(addprefix $(OBJ_PATH), $(addsuffix .o, $(FILES)))

.PHONY: clean fclean re samples samplesd

all: $(NAME)

$(NAME): $(OFILES) $(LIB)
	@$(CC) -o $(NAME) $(OFILES) -L. $(LIB)

$(LIB):
	@cd $(LIBFT) && $(MAKE)

$(OFILES): 
	@mkdir obj && cd obj && $(CC) $(WFLAGS) -I $(addprefix ../, $(HEADERS)) -c $(addprefix ../, $(CFILES))

samples:
	@tar -zxvf extern_file.txt

samplesd:
	@rm -rf samples

clean:
	@rm -rf $(OBJ_PATH) && cd $(LIBFT) && $(MAKE) clean

fclean: clean
	@rm -rf $(NAME) $(LIB)

re: fclean all
