/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 19:14:22 by anyo              #+#    #+#             */
/*   Updated: 2017/08/20 19:21:18 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_word_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (*(str + i) == c)
		i++;
	while (*(str + i) != c && *(str + i) != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**s2;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	if (!s || !(s2 = malloc(sizeof(*s2) * (ft_nbofwords(s, c) + 1))))
		return (NULL);
	while (++i < (int)ft_nbofwords(s, c))
	{
		k = 0;
		if (!(*(s2 + i) = ft_strnew(get_word_len(&s[j], c) + 1)))
			*(s2 + i) = NULL;
		while (*(s + j) == c)
			j++;
		while (*(s + j) != c && *(s + j))
			s2[i][k++] = *(s + j++);
		s2[i][k] = '\0';
	}
	*(s2 + i) = 0;
	return (s2);
}
