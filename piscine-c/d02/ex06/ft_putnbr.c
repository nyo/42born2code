/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 21:13:50 by anyo              #+#    #+#             */
/*   Updated: 2016/08/11 06:07:56 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putnbr(int nb)
{
	long int nbr;

	nbr = nb;
	if (n < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(nbr % 10 + '0');
}
