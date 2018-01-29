/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 18:53:00 by anyo              #+#    #+#             */
/*   Updated: 2016/08/12 16:54:00 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_higher_than_eleven(int hour)
{
	int		c;
	int		n;
	char	a;
	char	p;

	a = 'P';
	p = 'P';
	if (hour == 12)
	{
		printf("THE FOLLOWING TAKES PLACE BETWEEN 12.00 P.M. AND 1.00 P.M.\n");
	}
	else if (hour == 23)
	{
		printf("THE FOLLOWING TAKES PLACE BETWEEN 11.00 P.M. AND 12.00 A.M.\n");
	}
	else
	{
		c = hour - 12;
		n = c + 1;
		printf("THE FOLLOWING TAKES PLACE BETWEEN ");
		printf("%d.00 %c.M. AND %d.00 %c.M.\n", c, a, n, p);
	}
}

void	ft_lower_than_twelve(int hour)
{
	int		c;
	int		n;
	char	a;
	char	p;

	a = 'A';
	p = 'A';
	if (hour == 0)
		printf("THE FOLLOWING TAKES PLACE BETWEEN 12.00 A.M. AND 1.00 A.M.\n");
	else if (hour == 11)
		printf("THE FOLLOWING TAKES PLACE BETWEEN 11.00 A.M. AND 12.00 P.M.\n");
	else
	{
		c = hour;
		n = hour + 1;
		printf("THE FOLLOWING TAKES PLACE BETWEEN ");
		printf("%d.00 %c.M. AND %d.00 %c.M.\n", c, a, n, p);
	}
}

void	ft_takes_place(int hour)
{
	if (hour > 11)
	{
		ft_higher_than_eleven(hour);
	}
	else
	{
		ft_lower_than_twelve(hour);
	}
}
