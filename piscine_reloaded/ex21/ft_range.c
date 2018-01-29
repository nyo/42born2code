/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:11:58 by anyo              #+#    #+#             */
/*   Updated: 2016/11/03 12:27:14 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_how_many(int min, int max)
{
	if (min < max)
		return (max - min);
	else
		return (0);
}

int		*ft_range(int min, int max)
{
	int		*tab;
	int		i;

	i = 0;
	if (ft_how_many(min, max) == 0)
		return (NULL);
	else
	{
		tab = (int *)malloc(sizeof(*tab) * ft_how_many(min, max));
		while (i < ft_how_many(min, max))
		{
			tab[i] = min + i;
			i++;
		}
		return (tab);
	}
}
