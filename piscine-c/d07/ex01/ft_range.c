/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 09:52:40 by anyo              #+#    #+#             */
/*   Updated: 2016/08/16 17:36:25 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_array_size(int min, int max)
{
	if (min < max)
		return (max - min);
	else
		return (0);
}

int		*ft_range(int min, int max)
{
	int i;
	int j;
	int *nul;
	int *arr;

	nul = NULL;
	if (ft_array_size(min, max) != 0)
	{
		i = 0;
		j = ft_array_size(min, max);
		arr = (int *)malloc(sizeof(*arr) * j);
		while (i < j)
		{
			arr[i] = min + i;
			i += 1;
		}
		return (arr);
	}
	else
	{
		return (nul);
	}
}
