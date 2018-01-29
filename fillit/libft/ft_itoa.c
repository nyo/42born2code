/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:01:22 by anyo              #+#    #+#             */
/*   Updated: 2016/11/15 22:24:13 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_negative(long x, int len, char *ret)
{
	int	backslash0;

	backslash0 = len + 1;
	x = -x;
	ret[0] = '-';
	while (len > 0)
	{
		ret[len] = x % 10 + 48;
		x /= 10;
		len--;
	}
	ret[backslash0] = '\0';
}

static void	ft_positive(long x, int len, char *ret)
{
	int	backslash0;

	backslash0 = len;
	while (len > 0)
	{
		ret[len - 1] = x % 10 + 48;
		x /= 10;
		len--;
	}
	ret[backslash0] = '\0';
}

char		*ft_itoa(int n)
{
	long	x;
	int		len;
	char	*ret;

	x = n;
	len = ft_intlen(x);
	if (x < 0)
	{
		ret = (char *)malloc(sizeof(char) * (len + 2));
		if (ret == NULL)
			return (NULL);
		ft_negative(x, len, ret);
	}
	else
	{
		ret = (char *)malloc(sizeof(char) * (len + 1));
		if (ret == NULL)
			return (NULL);
		ft_positive(x, len, ret);
	}
	return (ret);
}
