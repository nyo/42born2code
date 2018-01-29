/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keep_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 21:56:01 by anyo              #+#    #+#             */
/*   Updated: 2016/08/20 21:56:02 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "protocolle.h"

char	*ft_keep_e(char *str)
{
	int		d;
	int		lw;
	int		lh;
	int		ttl;
	char	*s;

	s = (char *)malloc(sizeof(char) * 4);
	lw = ft_width(str);
	lh = ft_height(str);
	ttl = ft_strlen(str);
	d = (lw + 1) * (lh - 1);
	s[0] = str[d];
	s[1] = str[d + 1];
	s[2] = str[ttl - 2];
	s[3] = '\0';
	return (s);
}

char	*ft_s_keep_e(char *str)
{
	int		d;
	int		lw;
	int		lh;
	int		ttl;
	char	*s;

	s = (char *)malloc(sizeof(char) * 3);
	lw = ft_width(str);
	lh = ft_height(str);
	ttl = ft_strlen(str);
	d = (lw + 1) * (lh - 1);
	s[0] = str[d];
	s[1] = str[ttl - 2];
	s[2] = '\0';
	return (s);
}
