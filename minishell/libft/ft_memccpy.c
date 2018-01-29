/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:40:37 by anyo              #+#    #+#             */
/*   Updated: 2017/01/16 13:44:22 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = -1;
	ptr = dst;
	while (n > ++i)
	{
		*(ptr + i) = *((unsigned char *)src + i);
		if (*(ptr + i) == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
