/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:49:13 by anyo              #+#    #+#             */
/*   Updated: 2017/03/25 00:22:51 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	if (!s1)
		return (NULL);
	if (!(ptr = ft_strnew(ft_strlen(s1))))
		return (NULL);
	return (ft_strcpy(ptr, s1));
}
