/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:19:52 by anyo              #+#    #+#             */
/*   Updated: 2016/11/12 20:49:22 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*tmp1;
	const char	*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	while (*big)
	{
		tmp1 = big;
		tmp2 = little;
		while (*tmp1 == *tmp2 && *tmp1 && *tmp2)
		{
			tmp1++;
			tmp2++;
		}
		if (*tmp2 == '\0')
			return ((char *)big);
		big++;
	}
	if (ft_strlen(big) == 0 && ft_strlen(little) == 0)
		return ((char *)big);
	else
		return (NULL);
}
