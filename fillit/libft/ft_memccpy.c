/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:40:37 by anyo              #+#    #+#             */
/*   Updated: 2016/11/14 18:45:28 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;
	unsigned char	x;

	i = 0;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	x = (unsigned char)c;
	while (n > 0)
	{
		dst2[i] = src2[i];
		dst++;
		if (dst2[i] == x)
			return (dst);
		i++;
		n--;
	}
	return (NULL);
}
