/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 21:21:59 by anyo              #+#    #+#             */
/*   Updated: 2017/05/23 17:56:00 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	format_size() returns the size of of specified file, or its MAJOR/MINOR,
**	formatted as ls(1) does.
**	return value:
**		NULL - ERROR! malloc()
**		The size - OK!
**		The formatted MAJOR/MINOR thing - OK!
*/

char	*format_size(mode_t mode, dev_t id, size_t size)
{
	char	*ret;

	ret = NULL;
	if (!S_ISCHR(mode) && !S_ISBLK(mode))
		return (ft_itoa(size));
	else
	{
		if (!(ret = ft_strdup(ft_itoa(major(id)))))
			return (NULL);
		if (!(ret = ft_strjoin(ret, ", ")))
			return (NULL);
		if (!(ret = ft_strjoin(ret, ft_itoa(minor(id)))))
			return (NULL);
		if (!(ret = ft_strjoin(ret, "\0")))
			return (NULL);
	}
	return (ret);
}
