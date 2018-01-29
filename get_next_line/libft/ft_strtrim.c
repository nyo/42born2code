/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:45:52 by anyo              #+#    #+#             */
/*   Updated: 2017/01/17 19:23:11 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenght(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
		i++;
	while (*(s + j) == ' ' || *(s + j) == '\n' || *(s + j) == '\t')
		j--;
	return (i == ft_strlen(s) ? 0 : ft_strlen(s) - i - (ft_strlen(s) - 1 - j));
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s || !(ptr = ft_strnew(ft_lenght(s))))
		return (NULL);
	while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
		i++;
	while (j < ft_lenght(s))
		*(ptr + j++) = *(s + i++);
	*(ptr + j) = '\0';
	return (ptr);
}
