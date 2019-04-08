/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mate <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:05:52 by mate              #+#    #+#             */
/*   Updated: 2017/09/29 12:45:32 by mate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef intmax_t
# include <stdint.h>
#endif
#include <stdlib.h>

intmax_t	ft_recursive_power(intmax_t nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
