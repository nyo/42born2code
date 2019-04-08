/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:23:57 by anyo              #+#    #+#             */
/*   Updated: 2018/01/29 18:28:18 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	-------------------------------------------------------------------------- +
**	man 3 strndup
**	-------------------------------------------------------------------------- +
*/

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ptr;

	if (!(ptr = ft_strnew(n)))
		return (NULL);
	ft_strncpy(ptr, s1, n);
	*(ptr + n) = '\0';
	return (ptr);
}
