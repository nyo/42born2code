/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 21:15:33 by anyo              #+#    #+#             */
/*   Updated: 2016/08/21 21:15:34 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "protocolle.h"

int		ft_check_size(char *str)
{
	if (ft_strlen(str) == 2)
	{
		if (str[0] == 'A')
			return (3);
		else if (str[0] == 'o')
			return (4);
		else if (str[0] == '/')
			return (5);
	}
	else if (ft_strlen(str) == 6)
	{
		if (str[0] == 'A' && str[2] == 'C')
			return (2);
	}
	else if (ft_strlen(str) == 3)
	{
		if (str[0] == 'A' && str[1] == 'C')
			return (1);
		else if (str[0] == 'o')
			return (6);
		else if (str[0] == '/')
			return (7);
	}
	return (0);
}
