/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 23:58:31 by anyo              #+#    #+#             */
/*   Updated: 2016/08/20 12:31:01 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ligne_x1(int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
		{
			ft_putchar('o');
			if (x == 1)
			{
				ft_putchar('\n');
			}
		}
		else if (i == x - 1)
		{
			ft_putchar('o');
			ft_putchar('\n');
		}
		else
		{
			ft_putchar('-');
		}
		i++;
	}
}

void	ligne_x2(int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
		{
			ft_putchar('|');
			if (x == 1)
			{
				ft_putchar('\n');
			}
		}
		else if (i == x - 1)
		{
			ft_putchar('|');
			ft_putchar('\n');
		}
		else
		{
			ft_putchar(' ');
		}
		i++;
	}
}

void	colle(int x, int y)
{
	int j;

	j = 0;
	while (j < y)
	{
		if (j == 0 || j == y - 1)
		{
			ligne_x1(x);
		}
		else
		{
			ligne_x2(x);
		}
		j++;
	}
}
