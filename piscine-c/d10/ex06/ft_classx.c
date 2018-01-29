/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_classx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 12:20:31 by anyo              #+#    #+#             */
/*   Updated: 2016/08/24 13:36:55 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "protodo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i += 1;
	}
}

void	ft_putnbr(int nb)
{
	long int nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar(nbr % 10 + '0');
}

int		ft_atoi(char *str)
{
	int i;
	int nb;
	int neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (str[i] < 33)
		i += 1;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i += 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i += 1;
	}
	return ((neg == 1) ? (-nb) : (nb));
}
