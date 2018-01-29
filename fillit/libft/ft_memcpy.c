/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:24:57 by anyo              #+#    #+#             */
/*   Updated: 2016/11/09 12:11:54 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst2;
	unsigned char *src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (n > 0)
	{
		*dst2 = *src2;
		dst2++;
		src2++;
		n--;
	}
	return (dst);
}
