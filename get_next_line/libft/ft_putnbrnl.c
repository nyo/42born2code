/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 20:19:12 by anyo              #+#    #+#             */
/*   Updated: 2017/01/20 00:06:17 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_putnbrnl() prints the number n, followed by a newline.
*/

void	ft_putnbrnl(int n)
{
	ft_putnbr(n);
	ft_putchar('\n');
}
