/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:41:07 by anyo              #+#    #+#             */
/*   Updated: 2016/08/13 14:43:18 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int i;
	int nbr;
	int negative;

	i = 0;
	nbr = 0;
	negative = 0;
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n')
			|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
		i += 1;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i += 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += ((int)str[i] - '0');
		i += 1;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}
