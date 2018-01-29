/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:16:57 by anyo              #+#    #+#             */
/*   Updated: 2017/06/06 22:40:03 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	fl_size() returns the correct size to malloc `char **filelist`
**	above this function.
**	return value:
**		-1 - ERROR! opendir() or closedir()
**		0 or greater - the calculated size, OK!
*/

static int	fl_size(char *name)
{
	struct dirent	*file_info;
	DIR				*directory;
	int				ret;

	ret = 0;
	directory = NULL;
	file_info = NULL;
	if (!(directory = opendir(name)))
		return (-1);
	while ((file_info = readdir(directory)))
		if (!(ISHIDDEN(*file_info->d_name)))
			ret++;
	if (closedir(directory) == -1)
		return (-1);
	return (ret);
}

/*
**	ls_basic() is a simple implementation of ls(1) with `-1` option on.
**	return value:
**		0 - ERROR! malloc(), opendir() or closedir()
**		1 - no more data to add, OK!
*/

int			ls_basic(char *name)
{
	struct dirent	*file_info;
	DIR				*directory;
	char			**filelist;
	int				i;

	i = 0;
	filelist = NULL;
	directory = NULL;
	file_info = NULL;
	if (!(filelist = malloc(sizeof(char *) * (fl_size(name) + 1))))
		return (0);
	if (!(directory = opendir(name)))
		return (0);
	while ((file_info = readdir(directory)))
		if (!(ISHIDDEN(*file_info->d_name)))
			if (!(*(filelist + i++) = ft_strdup(file_info->d_name)))
				return (0);
	if (closedir(directory) == -1)
		return (0);
	*(filelist + i) = NULL;
	ft_arrsort(filelist, i);
	ft_putarr(filelist);
	ft_arrfree(filelist);
	return (1);
}
