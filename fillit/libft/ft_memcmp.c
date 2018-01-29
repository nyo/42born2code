/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:58:55 by anyo              #+#    #+#             */
/*   Updated: 2016/11/08 15:45:19 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1bis;
	unsigned char *s2bis;

	s1bis = (unsigned char *)s1;
	s2bis = (unsigned char *)s2;
	while (n > 0)
	{
		if (*s1bis != *s2bis)
			return (*s1bis - *s2bis);
		s1bis++;
		s2bis++;
		n--;
	}
	return (0);
}
