/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sort_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:01:14 by anyo              #+#    #+#             */
/*   Updated: 2017/06/19 21:20:59 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	swap() swaps two strings of an array of char-pointers.
*/

static void	swap(char **arr, int i)
{
	char	*tmp;

	tmp = *(arr + i);
	*(arr + i) = *(arr + i + 1);
	*(arr + i + 1) = tmp;
}

/*
**	arr_sort_time() sorts the strings in the array of char-pointers,
**	by modification time.
*/

void		arr_sort_time(char **arr, char *dir, t_opt opt)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	len = ft_arrlen(arr);
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (gdate(*(arr + j), dir, opt) ==
					gdate(*(arr + j + 1), dir, opt))
			{
				if (ft_strcmp(*(arr + j), *(arr + j + 1)) > 0)
					swap(arr, j);
			}
			else if (gdate(*(arr + j), dir, opt) <
				gdate(*(arr + j + 1), dir, opt))
				swap(arr, j);
			j++;
		}
		i++;
	}
}
