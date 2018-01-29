/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 00:11:37 by anyo              #+#    #+#             */
/*   Updated: 2017/06/06 21:59:00 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	ft_arrrev() reverses the order of the given array of char-pointers.
*/

void	ft_arrrev(char **arr)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_arrlen(arr) - 1;
	tmp = NULL;
	while (i <= j)
	{
		tmp = *(arr + i);
		*(arr + i) = *(arr + j);
		*(arr + j) = tmp;
		i++;
		j--;
	}
}
