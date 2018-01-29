# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anyo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/28 11:13:29 by anyo              #+#    #+#              #
#    Updated: 2017/09/28 15:35:20 by anyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
CC = gcc
LIB = -ltermcap
FLAGS = -Wall -Wextra -Werror

SRC_PATH = srcs/
OBJ_PATH = objs/
LFT_PATH = libft/
INC_PATH = includes/

INC_FILES = ft_select.h
SRC_FILES = disp_back.c			\
			disp_check.c		\
			disp_list.c			\
			exec_key.c			\
			exec_select.c		\
			linked_list.c		\
			main.c				\
			press_stuff.c		\
			press_bonus.c		\
			signal_handler.c	\
			tc_putc.c			\
			term_mode.c
OBJ_FILES = $(SRC_FILES:.c=.o)

INCS = $(addprefix -I, $(INC_PATH))
LIBFT = $(addprefix $(LFT_PATH), libft.a)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ_FILES))
HEADERS = $(addprefix $(INC_PATH), $(INC_FILES))

C_RED = \033[31m
C_BLUE = \033[36m
C_GREEN = \033[32m
C_WHITE = \033[37m
C_RESET = \033[0m
C_BOLD_BLUE = \033[1;36m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -sC $(LFT_PATH) fclean && $(MAKE) -sC $(LFT_PATH)
	@echo "$(C_GREEN)Libft has been built...$(C_RESET)"
	@$(CC) $(FLAGS) $(LIB) $(LIBFT) $(OBJS) -o $(NAME)
	@echo "$(C_BLUE)./$(NAME) is $(C_BOLD_BLUE)READY$(C_RESET)$(C_BLUE)!$(C_RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS) Makefile
	@mkdir -p $(OBJ_PATH)
	@echo "$(C_WHITE)Object file has been created...$(C_RESET)"
	@$(CC) $(FLAGS) $(INCS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(C_RED)Object files directory has been deleted.$(C_RESET)"
	@$(MAKE) -sC $(LFT_PATH) clean
	@echo "$(C_RED)Libft has been cleaned: removed object files.$(C_RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(C_RED)$(NAME) has been deleted.$(C_RESET)"
	@$(MAKE) -sC $(LFT_PATH) fclean
	@echo "$(C_RED)Libft has been cleaned: removed $(LIBFT)$(C_RESET)"

re: fclean all
