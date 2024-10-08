/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo                                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:24:38 by anyo              #+#    #+#             */
/*   Updated: 2016/11/15 22:24:38 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}
