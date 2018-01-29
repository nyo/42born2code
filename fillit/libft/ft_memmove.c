/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:01:44 by anyo              #+#    #+#             */
/*   Updated: 2016/11/15 21:49:07 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}
