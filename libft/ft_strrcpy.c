/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:43:55 by anyo              #+#    #+#             */
/*   Updated: 2018/01/29 17:46:50 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	-------------------------------------------------------------------------- +
**	Copies the string `src`, from index `start`, to `dst`.
**	-------------------------------------------------------------------------- +
*/

char	*ft_strrcpy(char *dst, const char *src, size_t start)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(src + i) && i < start)
		i++;
	while (*(src + i))
		*(dst + j++) = *(src + i++);
	*(dst + j) = '\0';
	return (dst);
}
