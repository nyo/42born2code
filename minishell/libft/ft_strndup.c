/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 16:41:21 by anyo              #+#    #+#             */
/*   Updated: 2017/08/08 16:44:24 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*ptr;

	if (!s1)
		return (NULL);
	if (!(ptr = ft_strnew(n)))
		return (NULL);
	ft_strncpy(ptr, s1, n);
	*(ptr + n) = '\0';
	return (ptr);
}
