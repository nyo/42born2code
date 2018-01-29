/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 11:05:34 by anyo              #+#    #+#             */
/*   Updated: 2016/08/06 19:13:01 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		nb_of_lines(int x)
{
	int i;
	int nb_lines1;
	int nb_lines2;

	i = 0;
	nb_lines1 = 3;
	nb_lines2 = 0;
	while (i < x)
	{
		nb_lines2 += nb_lines1;
		nb_lines1 += 1;
		i += 1;
	}
	return (nb_lines2);
}

void	stage(int x)
{
	int i;
	int j;
	int k;

	i = 0;
	k = x;
	while (i < x)
	{
		j = 0;
		while (j < k)
		{
			ft_putchar('*');
			j += 1;
		}
		ft_putchar('\n');
		k += 1;
		i += 1;
	}
}

void write_line(int lenght)
{
	int i;

	i = 0;
	while(i < lenght)
	{
		if (i == lenght - 1)
		{
			ft_putchar('\\');
		}
		else
		{
			ft_putchar('*');
		}
		i += 1;
	}
	ft_putchar('\n');
}

void	sastantua(int size)
{
	int i;
	int j;
	int lines_per_stage;
	int char_per_line;

	i = 0;
	lines_per_stage = 3;
	char_per_line = 3;
	while (i < size)
	{	
		j = 0;	
		while (j < lines_per_stage)
		{
			write_line(char_per_line);
			char_per_line += 1;
			j += 1;
		}
		lines_per_stage += 1;
		char_per_line += 3;
		i += 1;
	}
}

int		main(void)
{
	sastantua(3);
	return (0);
}
