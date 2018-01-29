/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 16:52:44 by anyo              #+#    #+#             */
/*   Updated: 2016/08/23 05:09:13 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

int						ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

char					*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (src[i])
		i += 1;
	dest = (char *)malloc(sizeof(*dest) * (i + 1));
	while (src[j])
	{
		dest[j] = src[j];
		j += 1;
	}
	dest[j] = '\0';
	return (dest);
}

struct	s_stock_par		*ft_param_to_tab(int ac, char **av)
{
	int			i;
	t_stock_par	*arr;

	i = 0;
	arr = (t_stock_par *)malloc(sizeof(t_stock_par) * ac + 1);
	while (i < ac)
	{
		arr[i].size_param = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		arr[i].tab = ft_split_whitespaces(av[i]);
		i += 1;
	}
	arr[i].str = NULL;
	return (arr);
}
