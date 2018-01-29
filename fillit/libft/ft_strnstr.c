/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:48:08 by anyo              #+#    #+#             */
/*   Updated: 2016/11/08 15:46:56 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*tmp1;
	const char	*tmp2;

	i = 0;
	tmp1 = NULL;
	tmp2 = NULL;
	while (*big && i < len)
	{
		j = i;
		tmp1 = big;
		tmp2 = little;
		while (*tmp1 == *tmp2 && *tmp1 && *tmp2 && j < len)
		{
			tmp1++;
			tmp2++;
			j++;
		}
		if (*tmp2 == '\0')
			return ((char *)big);
		big++;
		i++;
	}
	return ((ft_strlen(big) == 0 && ft_strlen(little) == 0) ? "" : NULL);
}
