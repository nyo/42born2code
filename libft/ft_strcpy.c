/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:25:16 by anyo              #+#    #+#             */
/*   Updated: 2017/11/30 16:22:00 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	-------------------------------------------------------------------------- +
**	man 3 strcpy
**	-------------------------------------------------------------------------- +
*/

char	*ft_strcpy(char *dst, const char *src)
{
	ft_strncpy(dst, src, ft_strlen(src));
	*(dst + ft_strlen(src)) = '\0';
	return (dst);
}
