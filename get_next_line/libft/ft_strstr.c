/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:19:52 by anyo              #+#    #+#             */
/*   Updated: 2017/01/16 18:25:37 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*ptr1;
	const char	*ptr2;

	while (*big)
	{
		ptr1 = big;
		ptr2 = little;
		while (*ptr1 && *ptr2 && *ptr1 == *ptr2)
		{
			ptr1++;
			ptr2++;
		}
		if (*ptr2 == '\0')
			return ((char *)big);
		big++;
	}
	return (!(ft_strlen(big)) && !(ft_strlen(little)) ? (char *)big : NULL);
}
