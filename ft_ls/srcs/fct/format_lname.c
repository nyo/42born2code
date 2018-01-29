/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_lname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:46:07 by anyo              #+#    #+#             */
/*   Updated: 2017/05/23 19:09:30 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	format_lname() returns the formatted linkname, as `ls -l` does.
**	return value:
**		NULL - ERROR! malloc() or readlink()
**		The formatted lname - OK!
*/

char	*format_lname(char *filename, char *path, off_t size)
{
	char	*ret;
	char	*linkname;
	ssize_t	r;

	if (!(linkname = ft_strnew(size)))
		return (NULL);
	if ((r = readlink(path, linkname, size + 1)) < 0)
		return (NULL);
	linkname[size] = '\0';
	if (!(ret = ft_strdup(filename)))
		return (NULL);
	if (!(ret = ft_strjoin(ret, " -> ")))
		return (NULL);
	if (!(ret = ft_strjoin(ret, linkname)))
		return (NULL);
	free(linkname);
	return (ret);
}
