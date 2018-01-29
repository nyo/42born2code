/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:45:52 by anyo              #+#    #+#             */
/*   Updated: 2016/11/14 20:37:38 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wanted_len(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	return (i == ft_strlen(s) ? 0 : ft_strlen(s) - i - (ft_strlen(s) - 1 - j));
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * (ft_wanted_len(s) + 1));
	if (ret == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < ft_wanted_len(s))
	{
		ret[j] = s[i];
		j++;
		i++;
	}
	ret[j] = '\0';
	return (ret);
}
