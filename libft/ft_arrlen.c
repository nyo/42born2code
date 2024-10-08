/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:16:48 by anyo              #+#    #+#             */
/*   Updated: 2018/01/27 17:23:32 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	-------------------------------------------------------------------------- +
**	Computes the lenght of the given array.
**	-------------------------------------------------------------------------- +
*/

size_t	ft_arrlen(char **arr)
{
	size_t	i;

	i = -1;
	while (*(arr + ++i))
		;
	return (i);
}
