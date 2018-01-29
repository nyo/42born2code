/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 10:43:28 by anyo              #+#    #+#             */
/*   Updated: 2016/08/14 10:43:44 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_who_is_bigger(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
		i += 1;
	while (s2[j])
		j += 1;
	if (i >= j)
		return (i);
	else if (j > i)
		return (j);
}

int		match(char *s1, char *s2)
{
	int i;
	int j;
	int k;
	int l;
	int m;

	i = 0;
	j = ft_who_is_bigger(s1, s2);
	k = 0;
	while (i < j)
	{
		m = 0;
		l = 0;
		if (s2[i] == s1[i])
			k += 1;
		else if (s2[i] == '*')
		{
			l = i;
			m = i;
			while (s2[l] == '*')
				l += 1;
			while (s1[m] != s2[l])
				m += 1;
			if (s1[m] == s2[l])
				k += 1;	
		}
		if (m != 0 && l != 0)
			i = m;
		else
			i += 1;
	}
	if (k == j)
		return (1);
	else
		return (0);
}

int		main(int argc, char **argv)
{
	printf("%d", match(argv[1], argv[2]));
	return (0);
}