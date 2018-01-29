/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 13:41:34 by anyo              #+#    #+#             */
/*   Updated: 2016/08/24 13:41:36 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "protodo.h"

void	ft_add(int a, int b)
{
	ft_putnbr(a + b);
	ft_putstr("\n");
}

void	ft_sub(int a, int b)
{
	ft_putnbr(a - b);
	ft_putstr("\n");
}

void	ft_mul(int a, int b)
{
	ft_putnbr(a * b);
	ft_putstr("\n");
}

void	ft_div(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(a / b);
	ft_putstr("\n");
}

void	ft_mod(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(a % b);
	ft_putstr("\n");
}
