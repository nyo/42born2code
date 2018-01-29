/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 12:51:29 by anyo              #+#    #+#             */
/*   Updated: 2016/08/10 18:50:39 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int j;
	int intermediaire;

	j = 0;
	while (j < size)
	{
		i = 0;
		// sort du tableau au dernier char
		while (tab[i] > tab[i + 1])
		{
			intermediaire = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = intermediaire;
			i += 1;
		}
		j += 1;
	}
}
