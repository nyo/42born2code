/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:50:54 by anyo              #+#    #+#             */
/*   Updated: 2016/11/14 20:34:08 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*ret;

	if (s == NULL)
		return (NULL);
	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret == NULL)
		return (NULL);
	while (*s)
	{
		ret[i] = f(*s);
		i++;
		s++;
	}
	ret[i] = '\0';
	return (ret);
}
