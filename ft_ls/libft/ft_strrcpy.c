/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 20:22:35 by anyo              #+#    #+#             */
/*   Updated: 2017/01/20 00:00:36 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_strrcpy() copy the string src (from 'start') to dst.
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
