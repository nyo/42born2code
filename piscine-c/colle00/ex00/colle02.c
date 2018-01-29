/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 18:30:27 by anyo              #+#    #+#             */
/*   Updated: 2016/08/07 18:32:49 by anyo             ###   ########.fr       */
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
			ft_putchar('A');
			if (x == 1)
			{
				ft_putchar('\n');
			}
		}
		else if (i == x - 1)
		{
			ft_putchar('A');
			ft_putchar('\n');
		}
		else
		{
			ft_putchar('B');
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
			ft_putchar('C');
			if (x == 1)
			{
				ft_putchar('\n');
			}
		}
		else if (i == x - 1)
		{
			ft_putchar('C');
			ft_putchar('\n');
		}
		else
		{
			ft_putchar('B');
		}
		i++;
	}
}

void	ligne_x3(int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
		{
			ft_putchar('B');
			if (x == 1)
			{
				ft_putchar('\n');
			}
		}
		else if (i == x - 1)
		{
			ft_putchar('B');
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
		if (j == 0)
		{
			ligne_x1(x);
		}
		else if (j == y - 1)
		{
			ligne_x2(x);
		}
		else
		{
			ligne_x3(x);
		}
		j++;
	}
}
