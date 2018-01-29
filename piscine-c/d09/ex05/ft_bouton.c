/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bouton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 10:54:44 by anyo              #+#    #+#             */
/*   Updated: 2016/08/12 16:54:31 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_bouton(int i, int j, int k)
{
	if ((k > i && i > j) || (j > i && i > k))
		return (i);
	else if ((k > j && j > i) || (i > j && j > k))
		return (j);
	else if ((j > k && k > i) || (j > k && k > i))
		return (k);
	else if (i == k || i == j)
		return (i);
	else if (k == j)
		return (k);
	else
		return (0);
}
