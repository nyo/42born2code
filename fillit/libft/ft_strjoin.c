/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:36:24 by anyo              #+#    #+#             */
/*   Updated: 2016/11/14 21:11:06 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ret = (char *)malloc(sizeof(ret) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret == NULL)
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strcat(ret, s2);
	return (ret);
}
