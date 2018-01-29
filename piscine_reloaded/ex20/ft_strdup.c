/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:04:43 by anyo              #+#    #+#             */
/*   Updated: 2016/11/03 12:28:53 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	ret = (char *)malloc(sizeof(*ret) * (i + 1));
	while (src[j])
	{
		ret[j] = src[j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
