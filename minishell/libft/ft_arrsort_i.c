/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsort_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:32:51 by anyo              #+#    #+#             */
/*   Updated: 2017/06/06 21:43:15 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	fl_arrsort_i() sorts the last `i` strings of an array of char-pointers by
**	ASCII value (lowest2highest).
*/

void	ft_arrsort_i(char **arr, int i)
{
	char	*tmp;
	int		j;
	int		k;

	j = 0;
	tmp = NULL;
	while (j < i)
	{
		k = 0;
		while (k < i)
		{
			if (*(arr - i + k + 1) &&
					ft_strcmp(*(arr - i + k), *(arr - i + k + 1)) > 0)
			{
				tmp = *(arr - i + k);
				*(arr - i + k) = *(arr - i + k + 1);
				*(arr - i + k + 1) = tmp;
			}
			k++;
		}
		j++;
	}
}
