/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:21:17 by anyo              #+#    #+#             */
/*   Updated: 2016/11/14 20:35:07 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	if (s == NULL)
		return (NULL);
	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret == NULL)
		return (NULL);
	while (*s)
	{
		ret[i] = f(i, *s);
		i++;
		s++;
	}
	ret[i] = '\0';
	return (ret);
}
