/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:50:54 by anyo              #+#    #+#             */
/*   Updated: 2017/01/17 18:48:28 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*ptr;

	i = -1;
	if (!s || !(ptr = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*(s + ++i))
		*(ptr + i) = f(*(s + i));
	*(ptr + i) = '\0';
	return (ptr);
}
