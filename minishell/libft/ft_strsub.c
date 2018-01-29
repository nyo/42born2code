/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:27:59 by anyo              #+#    #+#             */
/*   Updated: 2017/01/17 19:03:36 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s || !(ptr = ft_strnew(len)))
		return (NULL);
	while (len > i)
		*(ptr + i++) = *(s + start++);
	*(ptr + i) = '\0';
	return (ptr);
}
