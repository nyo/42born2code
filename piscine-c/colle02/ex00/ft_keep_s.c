/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keep_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 21:55:46 by anyo              #+#    #+#             */
/*   Updated: 2016/08/20 21:55:48 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "protocolle.h"

char	*ft_keep_s(char *str)
{
	int		lw;
	char	*s;

	s = (char *)malloc(sizeof(char *) * 4);
	lw = ft_width(str);
	s[0] = str[0];
	s[1] = str[1];
	s[2] = str[lw - 1];
	s[3] = '\0';
	return (s);
}

char	*ft_s_keep_s(char *str)
{
	int		lw;
	char	*s;

	s = (char *)malloc(sizeof(char *) * 3);
	lw = ft_width(str);
	s[0] = str[0];
	s[1] = str[lw - 1];
	s[2] = '\0';
	return (s);
}
