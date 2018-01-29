/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 11:59:42 by anyo              #+#    #+#             */
/*   Updated: 2016/08/12 16:55:04 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture2(unsigned int base)
{
	int i;

	i = 0;
	while (base != 1)
	{
		if (base % 2 == 0)
			base = base / 2;
		else
			base = (base * 3) + 1;
		i += 1;
	}
	return (i);
}
