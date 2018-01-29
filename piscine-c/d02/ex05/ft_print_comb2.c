/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 13:08:44 by anyo              #+#    #+#             */
/*   Updated: 2016/08/10 18:51:27 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

// ':'
void	ft_boucle(char a, char b, char c, char d)
{
	while (!((a == 9) && (b == 9)))
	{
		ft_putchar('0' + a);
		ft_putchar('0' + b);
		ft_putchar(' ');
		ft_putchar('0' + c);
		ft_putchar('0' + d);
		if (!((a == 9) && (b == 8)))
			ft_putchar(',');
		if (!((a == 9) && (b == 8)))
			ft_putchar(' ');
		d += 1;
		if ((d = d % 10) == 0)
			c += 1;
		if (c == 10)
		{
			c = a;
			b += 1;
			if ((b = b % 10) == 0)
				a += 1;
			d = b + 1;
		}
	}
}

void	ft_print_comb2(void)
{
	char nb[4];

	nb[0] = 0;
	nb[1] = 0;
	nb[2] = 0;
	nb[3] = 1;
	ft_boucle(nb[0], nb[1], nb[2], nb[3]);
}
