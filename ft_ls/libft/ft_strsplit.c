/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:51:13 by anyo              #+#    #+#             */
/*   Updated: 2017/01/20 00:26:32 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_split(char **ret, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i] && j < ft_nbofwords(s, c))
	{
		k = 0;
		if (s[i] == c)
			i++;
		while (s[i] != c)
		{
			ret[j][k] = s[i];
			i++;
			k++;
			if (s[i] == c)
			{
				ret[j][k] = '\0';
				j++;
			}
		}
	}
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**ptr;

	i = -1;
	if (!s ||
		!(ptr = (char **)malloc(sizeof(char *) * (ft_nbofwords(s, c) + 1))))
		return (NULL);
	while (++i < ft_nbofwords(s, c))
		if (!(*(ptr + i) = ft_strnew(ft_wordilen(s, c, i))))
			return (NULL);
	ft_split(ptr, s, c);
	*(ptr + i) = NULL;
	return (ptr);
}
