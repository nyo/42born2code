/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 13:34:54 by anyo              #+#    #+#             */
/*   Updated: 2016/08/22 13:44:24 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int j;
	int *tablo;

	i = 0;
	j = 0;
	while (i < length)
	{
		f(tab[i]);
		i += 1;
	}
	tablo = (int *)malloc(sizeof(int) * i);
	while (j < i)
	{
		tablo[j] = f(tab[j]);
		j += 1;
	}
	return (tablo);
}
