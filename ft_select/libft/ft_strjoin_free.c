/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:33:43 by anyo              #+#    #+#             */
/*   Updated: 2017/09/25 20:38:01 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_strjoin_free() does the same as ft_strjoin(), but let us decide if we
**	want to free the content of s1 (choice == 1), both s1 and s2 (choice == 2)
**	or none of them (choice == 0)
*/

char	*ft_strjoin_free(char *s1, char *s2, int choice)
{
	char	*ptr;

	if (!s1 || !s2 || !(ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strcat(ptr, s2);
	if (choice == 1)
		ft_strdel(&s1);
	else if (choice == 2)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (ptr);
}
