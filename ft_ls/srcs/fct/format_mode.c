/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 21:14:18 by anyo              #+#    #+#             */
/*   Updated: 2017/06/07 22:57:53 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	arg_type() returns the letter corresponding to the type of the file.
**	return value:
**		The corresponding letter - OK!
**		(if nothing corresponds, it returns '-' a.k.a `default` file type)
*/

static char	arg_type(mode_t mode)
{
	if ((S_ISDIR(mode)))
		return ('d');
	else if ((S_ISCHR(mode)))
		return ('c');
	else if ((S_ISBLK(mode)))
		return ('b');
	else if ((S_ISFIFO(mode)))
		return ('p');
	else if ((S_ISLNK(mode)))
		return ('l');
	else if ((S_ISSOCK(mode)))
		return ('s');
	else
		return ('-');
}

/*
**	format_mode() returns the full mode of a file, formatted as ls(1) does.
**	return value:
**		NULL - ERROR! malloc()
**		The null-terminated string - no more data to add, OK!
*/

char		*format_mode(mode_t mode)
{
	char	*ret;

	if (!(ret = ft_strnew(10)))
		return (NULL);
	ret[0] = arg_type(mode);
	ret[1] = (mode & S_IRUSR) ? 'r' : '-';
	ret[2] = (mode & S_IWUSR) ? 'w' : '-';
	ret[3] = (mode & S_IXUSR) ? 'x' : '-';
	ret[4] = (mode & S_IRGRP) ? 'r' : '-';
	ret[5] = (mode & S_IWGRP) ? 'w' : '-';
	ret[6] = (mode & S_IXGRP) ? 'x' : '-';
	ret[7] = (mode & S_IROTH) ? 'r' : '-';
	ret[8] = (mode & S_IWOTH) ? 'w' : '-';
	if ((mode & S_ISVTX))
		ret[9] = 't';
	else if ((mode & S_IXOTH))
		ret[9] = 'x';
	else if ((mode & S_ISUID) || (mode & S_ISGID))
		ret[9] = 's';
	else
		ret[9] = '-';
	ret[10] = '\0';
	return (ret);
}
