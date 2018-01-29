/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 17:55:48 by anyo              #+#    #+#             */
/*   Updated: 2016/08/18 09:55:47 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int g_k;
int g_l;

int		ft_is_empty(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			j += 1;
		i += 1;
	}
	return ((i == j) ? (1) : (0));
}

int		ft_nb_of_words(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			&& (i != 0) && (str[i - 1] > 32))
		{
			g_k = i;
			g_l = 0;
			while (str[g_k] == ' ' || str[g_k] == '\n' || str[g_k] == '\t')
			{
				g_l += 1;
				g_k += 1;
			}
			if (str[i + g_l] > 32)
				j += 1;
			i += g_l;
		}
		else
			i += 1;
	}
	return (j + 1);
}

int		ft_max_word_lenght(char *str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			j = 0;
		else if (str[i] > 32)
			j += 1;
		if (j > k)
			k = j;
		i += 1;
	}
	return (k);
}

void	ft_browse(char **tab, char *str, int nb_of_words)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (str[i] && k < nb_of_words)
	{
		j = 0;
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i += 1;
		while (str[i] != ' ' && str[i] != '\n'
			&& str[i] != '\t' && str[i] != '\0')
		{
			tab[k][j] = str[i];
			i += 1;
			j += 1;
			if (str[i] == ' ' || str[i] == '\n'
				|| str[i] == '\t' || str[i] == '\0')
			{
				tab[k][j] = '\0';
				k += 1;
			}
		}
	}
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		nb_of_words;
	int		max_word_lenght;
	char	**tab;

	if (ft_is_empty(str) == 0)
	{
		i = 0;
		nb_of_words = ft_nb_of_words(str);
		max_word_lenght = ft_max_word_lenght(str);
		tab = (char **)malloc(sizeof(char *) * (nb_of_words + 1));
		while (nb_of_words > 0 && nb_of_words > i)
		{
			tab[i] = (char *)malloc(sizeof(char) * (max_word_lenght + 1));
			i += 1;
		}
		ft_browse(tab, str, nb_of_words);
		tab[nb_of_words] = NULL;
	}
	else
	{
		tab = (char **)malloc(sizeof(char *) * 1);
		tab[0] = NULL;
	}
	return (tab);
}
