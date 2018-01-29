/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sort_time_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:10:30 by anyo              #+#    #+#             */
/*   Updated: 2017/06/19 21:20:58 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	swap() swaps two strings of an array of char-pointers.
*/

static void	swap(char **arr, int i, int len)
{
	char	*tmp;

	tmp = *(arr - len + i);
	*(arr - len + i) = *(arr - len + i + 1);
	*(arr - len + i + 1) = tmp;
}

/*
**	arr_sort_time_i() sorts the last `x` strings in the given list,
**	by modification time.
*/

void		arr_sort_time_i(char **arr, char *dir, t_opt opt, int x)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	len = x;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (gdate(*(arr - len + j), dir, opt) ==
					gdate(*(arr - len + j + 1), dir, opt))
			{
				if (ft_strcmp(*(arr - len + j), *(arr - len + j + 1)) > 0)
					swap(arr, j, len);
			}
			else if (gdate(*(arr - len + j), dir, opt) <
				gdate(*(arr - len + j + 1), dir, opt))
				swap(arr, j, len);
			j++;
		}
		i++;
	}
}
