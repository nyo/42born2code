/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bin0me                                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:44:36 by bin0me            #+#    #+#             */
/*   Updated: 2016/12/06 15:56:14 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_cntwrds(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	if (!*s)
		return (0);
	while (*s && *s != c)
		s++;
	return (ft_cntwrds(s, c) + 1);
}

static int		ft_strlenc(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char		*ft_strdupc(char const *src, char c)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = (char *)malloc(sizeof(char) * (ft_strlenc(src, c) + 1));
	if (!cpy)
		return (NULL);
	while (src[i] && src[i] != c)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		wrds;
	char	**tab;

	i = 0;
	if (!s || !*s)
		return (NULL);
	wrds = ft_cntwrds(s, c);
	if (!wrds)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (wrds + 1))))
		return (NULL);
	tab[wrds--] = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			tab[i] = ft_strdupc(s, c);
			s += ft_strlenc(s, c);
		}
		i++;
	}
	return (tab);
}
