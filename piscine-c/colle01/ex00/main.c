/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 22:47:23 by anyo              #+#    #+#             */
/*   Updated: 2016/08/14 22:51:12 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check(int nb, char **sudoku, int i, int j);
int		ft_check_argv(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);

int		solve(char **sudoku, int ncase)
{
	int i;
	int j;
	int k;

	k = 1;
	i = ncase / 8;
	j = ncase % 8 - 1;
	if (i * j > 81)
		return (1);
	if (sudoku[i][j] != '.')
		return (solve(sudoku, ncase + 1));
	while (k < 9)
	{
		if (check(k, sudoku, i, j))
		{
			sudoku[i][j] = k + '0';
			if (solve(sudoku, ncase))
				return (1);
		}
		k++;
	}
	sudoku[i][j] = '.';
	return (0);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (ft_check_argv(argv[i]) != 1 || argc != 10)
		{
			ft_putstr("Erreur\n");
			return (0);
		}
		i++;
	}
	solve(argv, 0);
	i = 1;
	while (argv[i])
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
