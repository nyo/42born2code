/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 22:47:38 by anyo              #+#    #+#             */
/*   Updated: 2016/08/14 22:48:42 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		line(int nb, char **sudoku, int j)
{
	int l;

	l = 0;
	while (l < 9)
	{
		if (sudoku[l][j] == nb + '0')
			return (0);
		l++;
	}
	return (1);
}

int		column(int nb, char **sudoku, int i)
{
	int c;

	c = 0;
	while (c < 9)
	{
		if (sudoku[i][c] == nb + '0')
			return (0);
		c++;
	}
	return (1);
}

int		block(int nb, char **sudoku, int i, int j)
{
	i -= i % 3;
	j -= j % 3;
	while (i < i + 3)
	{
		while (j < j + 3)
		{
			if (sudoku[i][j] == nb + '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check(int nb, char **sudoku, int i, int j)
{
	if (line(nb, sudoku, j) && column(nb, sudoku, i) && block(nb, sudoku, i, j))
		return (1);
	else
		return (0);
}
