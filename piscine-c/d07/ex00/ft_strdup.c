/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 17:22:03 by anyo              #+#    #+#             */
/*   Updated: 2016/08/16 17:36:16 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (src[i])
		i += 1;
	dest = (char *)malloc(sizeof(*dest) * (i + 1));
	while (src[j])
	{
		dest[j] = src[j];
		j += 1;
	}
	dest[j] = '\0';
	return (dest);
}
