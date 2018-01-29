/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bin0me                                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:05:57 by bin0me            #+#    #+#             */
/*   Updated: 2016/12/04 17:51:25 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	add_piece(int col, int row, char **tab, t_piece *piece)
{
	int		y;
	int		x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 5)
		{
			if ((piece->str)[y * 5 + x] == '#')
				tab[row + y][col + x] = piece->name;
			x++;
		}
		y++;
	}
}

static char	**create_map(int size)
{
	int		y;
	int		x;
	char	**tab;

	y = 0;
	tab = (char**)malloc(sizeof(char*) * (size + 1));
	tab[size] = 0;
	while (y < size)
	{
		tab[y] = (char*)malloc(sizeof(char) * (size + 1));
		x = 0;
		while (x < size)
		{
			tab[y][x] = '.';
			x++;
		}
		tab[y][x] = '\0';
		y++;
	}
	return (tab);
}

char		**print_solution(int size, t_piece *piece)
{
	int		y;
	int		x;
	char	**solution;

	y = 0;
	solution = create_map(size);
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (piece && piece->x == x && piece->y == y)
			{
				add_piece(x, y, solution, piece);
				piece = piece->next;
				x = -1;
				y = 0;
			}
			x++;
		}
		y++;
	}
	return (solution);
}

void		show_result(int size, t_piece *lst)
{
	char	**solution;

	solution = print_solution(size, lst);
	while (*solution)
	{
		ft_putendl(*solution);
		solution++;
	}
}
