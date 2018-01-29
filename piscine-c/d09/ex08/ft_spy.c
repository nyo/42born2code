/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 12:55:33 by anyo              #+#    #+#             */
/*   Updated: 2016/08/12 16:55:16 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i])
			return (1);
		if (s2[i] > s1[i])
			return (-1);
		i += 1;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "president") == 0 ||
			ft_strcmp(argv[i], "attack") == 0 ||
			ft_strcmp(argv[i], "Powers") == 0)
		{
			write(1, "Alert!!!\n", 9);
			return (0);
		}
		i += 1;
	}
	return (0);
}
