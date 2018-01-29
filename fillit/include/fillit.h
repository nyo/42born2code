/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bin0me                                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:16:43 by bin0me            #+#    #+#             */
/*   Updated: 2016/12/06 16:19:11 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define BUF_SIZE 1
# define BITS unsigned short int

typedef struct s_piece	t_piece;
struct					s_piece
{
	char				name;
	char				*str;
	int					x;
	int					y;
	int					height;
	int					width;
	BITS				*bits;
	t_piece				*next;
};

BITS					*init_map(void);
char					**check_file(char *str);
t_piece					*new_piece(char name, char *str);
char					**print_solution(int size, t_piece *piece);
void					show_result(int size, t_piece *lst);
char					*file_to_str(char *filename);

BITS					isplace_piece(BITS *map, t_piece *piece, int size);
char					*trim_str(char *str);
int						ft_sqrt(int nb);
t_piece					*new_piece(char name, char *str);

#endif
