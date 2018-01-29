/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 22:24:05 by anyo              #+#    #+#             */
/*   Updated: 2016/08/14 01:52:13 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	i = 5;
	if (nb == 2147483647 || nb == 2)
		return (1);
	else if (nb <= 1)
		return (0);
	else if (nb <= 3)
		return (1);
	else if ((nb % 2 == 0) || (nb % 3 == 0))
		return (0);
	while (i * i <= nb)
	{
		if ((nb % i == 0) || (nb % (i + 2) == 0))
			return (0);
		i += 6;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb < 0)
	{
		nb = 2;
	}
	while (ft_is_prime(nb) != 1)
	{
		nb += 1;
	}
	return (nb);
}
