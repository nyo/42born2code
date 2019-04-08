/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mate <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 11:08:02 by mate              #+#    #+#             */
/*   Updated: 2017/06/23 15:56:43 by mate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wstrtoa(wchar_t *wstr)
{
	char	*new;
	char	*tmp;

	new = ft_strnew(ft_wstrlen(wstr));
	while (*wstr)
	{
		if (!(tmp = ft_wchartoa(*wstr++)))
		{
			ft_strdel(&new);
			return (NULL);
		}
		new = ft_strcat(new, tmp);
		ft_strdel(&tmp);
	}
	return (new);
}
