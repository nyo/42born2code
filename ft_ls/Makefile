# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anyo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/31 18:39:01 by anyo              #+#    #+#              #
#    Updated: 2017/06/19 20:51:58 by anyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
GCC = gcc -Wall -Wextra -Werror
SOURCES = srcs/
INCLUDE = includes/
LIBFT = libft/
LIB = libft/libft.a
FILES = main.c	\
		arg/arg_fill.c	\
		arg/arg_len.c	\
		fct/al_clean.c	\
		fct/al_push.c	\
		fct/arr_sort_time.c	\
		fct/arr_sort_time_i.c	\
		fct/format_date.c	\
		fct/format_lname.c	\
		fct/format_mode.c	\
		fct/format_size.c	\
		fct/gdate.c	\
		fct/ls_basic.c	\
		fct/malloc_size.c	\
		opt/opt_fill.c	\
		opt/opt_is.c	\
		ret/ret_fill.c	\
		ret/ret_fill_ls_1.c	\
		ret/ret_fill_ls_br.c	\
		ret/ret_fill_notdir.c	\
		ret/ret_lst_ls_1.c	\
		ret/ret_lst_ls_br.c	\
		ret/ret_pl_values.c	\
		ret/ret_print_node.c	\
		ret/ret_reverse_lst.c

all: $(NAME)

$(NAME): $(LIB)
	@$(GCC) -I$(INCLUDE) -o $(NAME) $(addprefix $(SOURCES), $(FILES)) $(LIB)
	@echo "\x1b[32m./ft_ls is ready!\x1b[0m"

$(LIB):
	@$(MAKE) -sC $(LIBFT) fclean && $(MAKE) -sC $(LIBFT)

clean:
	@$(MAKE) -sC $(LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME) && $(MAKE) -sC $(LIBFT) fclean

re: fclean all

.PHONY: clean fclean re
