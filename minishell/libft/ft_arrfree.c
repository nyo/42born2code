/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 22:40:09 by anyo              #+#    #+#             */
/*   Updated: 2017/06/06 22:48:59 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	ft_arrfree() frees the array of char-pointers.
*/

void	ft_arrfree(char **arr)
{
	int	i;

	i = 0;
	while (*(arr + i))
	{
		free(*(arr + i));
		i++;
	}
	free(arr);
}
