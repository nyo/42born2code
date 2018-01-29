# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anyo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 14:08:51 by anyo              #+#    #+#              #
#    Updated: 2017/06/06 22:41:40 by anyo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCC = gcc -Wall -Wextra -Werror
CFILES = $(addsuffix .c, $(SRCS))
OFILES = $(addsuffix .o, $(SRCS))
SRCS = ./ft_memset 			\
	   ./ft_bzero 			\
	   ./ft_memcpy 			\
	   ./ft_memccpy 		\
	   ./ft_memmove 		\
	   ./ft_memchr 			\
	   ./ft_memcmp 			\
	   ./ft_strlen 			\
	   ./ft_strdup 			\
	   ./ft_strcpy 			\
	   ./ft_strncpy 		\
	   ./ft_strcat 			\
	   ./ft_strncat 		\
	   ./ft_strlcat 		\
	   ./ft_strchr 			\
	   ./ft_strrchr 		\
	   ./ft_strstr 			\
	   ./ft_strnstr 		\
	   ./ft_strcmp 			\
	   ./ft_strncmp			\
	   ./ft_atoi 			\
	   ./ft_isalpha			\
	   ./ft_isdigit			\
	   ./ft_isalnum			\
	   ./ft_isascii			\
	   ./ft_isprint 		\
	   ./ft_toupper 		\
	   ./ft_tolower 		\
	   ./ft_memalloc 		\
	   ./ft_memdel 			\
	   ./ft_strnew 			\
	   ./ft_strdel 			\
	   ./ft_strclr 			\
	   ./ft_striter 		\
	   ./ft_striteri 		\
	   ./ft_strmap 			\
	   ./ft_strmapi 		\
	   ./ft_strequ 			\
	   ./ft_strnequ 		\
	   ./ft_strsub 			\
	   ./ft_strjoin			\
	   ./ft_strtrim			\
	   ./ft_strsplit 		\
	   ./ft_itoa 			\
	   ./ft_putchar			\
	   ./ft_putstr 			\
	   ./ft_putendl			\
	   ./ft_putnbr 			\
	   ./ft_putchar_fd 		\
	   ./ft_putstr_fd 		\
	   ./ft_putendl_fd 		\
	   ./ft_putnbr_fd 		\
	   ./ft_lstnew 			\
	   ./ft_lstdelone 		\
	   ./ft_lstdel 			\
	   ./ft_lstadd 			\
	   ./ft_lstiter			\
	   ./ft_lstmap			\
	   ./ft_itc				\
	   ./ft_intlen			\
	   ./ft_nbofwords		\
	   ./ft_wordilen		\
	   ./ft_strrcpy			\
	   ./ft_strnjoin		\
	   ./ft_check			\
	   ./ft_putnbrnl		\
	   ./ft_putcolor		\
	   ./ft_arrlen			\
	   ./ft_putarr			\
	   ./ft_arrsort			\
	   ./ft_arrsort_i		\
	   ./ft_arrrev			\
	   ./ft_arrrev_i		\
	   ./ft_arrfree

all: $(NAME)

$(NAME):
	@$(GCC) -I ./ -c $(CFILES)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OFILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
