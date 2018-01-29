/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 11:30:59 by anyo              #+#    #+#             */
/*   Updated: 2016/08/11 11:10:17 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int res;
	int i;

	i = 1;
	res = 1;
	if (nb == 0 || nb == 1)
	{
		return (1);
	}
	else if (nb > 1 && nb < 13)
	{
		while (i <= nb)
		{
			res = res * i;
			i += 1;
		}
		return (res);
	}
	else
	{
		return (0);
	}
}
