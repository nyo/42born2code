/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:36:24 by anyo              #+#    #+#             */
/*   Updated: 2017/01/20 00:10:05 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_strnjoin() returns the result of the concatenation of
**	s1 and at most n characters of s2.
*/

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*ptr;

	if (!s1 || !s2 || !(ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strncat(ptr, s2, n);
	return (ptr);
}
