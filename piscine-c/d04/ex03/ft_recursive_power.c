/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 17:59:33 by anyo              #+#    #+#             */
/*   Updated: 2016/08/11 09:04:17 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power > 0)
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
	else if (power == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
