/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:24:38 by anyo              #+#    #+#             */
/*   Updated: 2017/01/19 23:35:32 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_intlen() returns the lenght of an int (in term of bytes).
*/

size_t	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		n = -n;
	while ((n /= 10) != 0)
		i++;
	return (i + 1);
}
