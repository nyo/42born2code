/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 16:23:35 by anyo              #+#    #+#             */
/*   Updated: 2016/08/15 17:59:13 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int g_i;
int g_j;
int g_k;

int		ft_str_lenght(int argc, char **argv)
{
	int i;
	int j;
	int k;

	i = 1;
	j = 0;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			k += 1;
			j += 1;
		}
		i += 1;
	}
	return (j);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		l;
	char	*str;

	g_i = 0;
	g_j = ft_str_lenght(argc, argv);
	g_k = 0;
	l = 1;
	str = (char *)malloc(sizeof(char *) * (g_j + argc - 1));
	while (g_i < g_j + argc - 2)
	{
		if (argv[l][g_k] != '\0')
		{
			str[g_i] = argv[l][g_k];
			g_k += 1;
		}
		else
		{
			str[g_i] = '\n';
			g_k = 0;
			l += 1;
		}
		g_i += 1;
	}
	str[g_i] = '\0';
	return (str);
}
