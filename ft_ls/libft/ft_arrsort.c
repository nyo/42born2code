/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 01:03:37 by anyo              #+#    #+#             */
/*   Updated: 2017/06/19 21:35:24 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	fl_arrsort() sorts an array of char-pointers by
**	ASCII value (lowest2highest).
*/

void	ft_arrsort(char **arr, int len)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = NULL;
	while (i < len)
	{
		j = 0;
		while (j < len && *(arr + j))
		{
			if (*(arr + j + 1) &&
					ft_strcmp(*(arr + j), *(arr + j + 1)) > 0)
			{
				tmp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = tmp;
			}
			j++;
		}
		i++;
	}
}
