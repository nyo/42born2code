/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mate <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:30:36 by mate              #+#    #+#             */
/*   Updated: 2017/08/07 14:08:07 by mate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strcjoin(char const *s1, char const *s2, char c)
{
	char	*dst;
	int		len;

	dst = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1);
		if (!(dst = ft_strnew(sizeof(char) * (len + ft_strlen(s2) + 1))))
			return (NULL);
		ft_strcpy(dst, s1);
		dst[len] = c;
		ft_strcpy(&dst[len + 1], s2);
	}
	return (dst);
}
