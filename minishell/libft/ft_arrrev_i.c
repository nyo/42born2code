/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrrev_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:40:07 by anyo              #+#    #+#             */
/*   Updated: 2017/06/06 21:59:26 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	ft_arrrev_i() reverses the order of the `i` last strings
**	in the given array of char-pointers.
*/

void	ft_arrrev_i(char **arr, int i)
{
	char	*tmp;
	int		j;
	int		k;

	j = 0;
	k = i;
	tmp = NULL;
	while (j < k)
	{
		tmp = *(arr - k + j);
		*(arr - k + j) = *(arr - j - 1);
		*(arr - j - 1) = tmp;
		j++;
		k--;
	}
}
