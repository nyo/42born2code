/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:01:22 by anyo              #+#    #+#             */
/*   Updated: 2017/01/20 00:33:37 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_negative(long x, int len, char *ret)
{
	int	backslash0;

	backslash0 = len + 1;
	x = -x;
	*ret = '-';
	while (len > 0)
	{
		*(ret + len--) = x % 10 + 48;
		x /= 10;
	}
	*(ret + backslash0) = '\0';
}

static void	ft_positive(long x, int len, char *ret)
{
	int	backslash0;

	backslash0 = len;
	while (len > 0)
	{
		*(ret + len-- - 1) = x % 10 + 48;
		x /= 10;
	}
	*(ret + backslash0) = '\0';
}

char		*ft_itoa(int n)
{
	long	x;
	int		len;
	char	*ret;

	x = n;
	len = (int)ft_intlen(x);
	if (x < 0)
	{
		if (!(ret = ft_strnew(len + 1)))
			return (NULL);
		ft_negative(x, len, ret);
	}
	else
	{
		if (!(ret = ft_strnew(len)))
			return (NULL);
		ft_positive(x, len, ret);
	}
	return (ret);
}
