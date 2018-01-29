# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anyo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/10 19:33:34 by anyo              #+#    #+#              #
#    Updated: 2017/08/26 14:31:15 by anyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
#FLAGS = -Wall -Wextra -Werror
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

C_0	= \033[0m
C_P	= \033[35m
C_G	= \033[32m
C_W	= \033[37m
C_B	= \033[36m
C_R	= \033[31m

SRC_PATH = srcs/
OBJ_PATH = objs/
LFT_PATH = libft/
INC_PATH = includes/

INC_FILES = minishell.h	\
			get_next_line.h
SRC_FILES = cmd_execute.c		\
			cmd_format.c		\
			cmd_replace_x.c		\
			display_prompt.c	\
			env_free.c			\
			env_init.c			\
			env_print.c			\
			env_to_arr.c		\
			env_to_environ.c	\
			get_cmd_path.c		\
			get_next_line.c		\
			is_line_blank.c		\
			main.c				\
			my_cd.c				\
			my_echo.c			\
			my_env.c			\
			my_exit.c			\
			my_setenv.c			\
			my_unsetenv.c		\
			my_togglecolor.c	\
			signal.c
OBJ_FILES = $(SRC_FILES:.c=.o)

LFT = libft/libft.a

SRCS = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ_FILES))
INCS = $(addprefix -I, $(INC_PATH))
INCSFULLPATH = $(addprefix $(INC_PATH), $(INC_FILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -sC $(LFT_PATH) fclean && $(MAKE) -sC $(LFT_PATH)
	@echo "$(C_G)Libft has been built...$(C_0)"
	@$(CC) $(FLAGS) $(LFT) $(OBJS) -o $(NAME)
	@echo "$(C_B)./minishell is $(C_P)READY$(C_B)!$(C_0)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCSFULLPATH) Makefile
	@mkdir -p $(OBJ_PATH)
	@echo "$(C_W)Object file has been created...$(C_0)"
	@$(CC) $(FLAGS) $(INCS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(C_R)Object files directory has been deleted.$(C_0)"
	@$(MAKE) -sC $(LFT_PATH) clean
	@echo "$(C_R)Libft has been cleaned.$(C_0)"

fclean: clean
	@rm -f $(NAME) && $(MAKE) -sC $(LFT_PATH) fclean
	@echo "$(C_R)Libft has been cleaned, removed \"$(LFT)\" & \"./$(NAME)\".$(C_0)"

re: fclean all
