/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:54:23 by anyo              #+#    #+#             */
/*   Updated: 2017/08/14 20:10:18 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int ret;
	int sign;

	i = 0;
	ret = 0;
	sign = 1;
	if (!str)
		return (0);
	while ((*(str + i) == ' ') || (*(str + i) == '\f') ||
			(*(str + i) == '\n') || (*(str + i) == '\r') ||
				(*(str + i) == '\t') || (*(str + i) == '\v'))
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '+' || *(str + i) == '-')
		i++;
	while (ft_isdigit(*(str + i)))
		ret = ret * 10 + (int)(*(str + i++) - '0');
	return (sign * ret);
}
