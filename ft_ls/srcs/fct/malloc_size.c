/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 01:10:46 by anyo              #+#    #+#             */
/*   Updated: 2017/05/23 18:01:07 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	malloc_size() returns the number of entries after a `ls -1a <name>`.
**	return value:
**		-1 - ERROR! opendir() or closedir()
**		0 or greater - the calculated size, OK!
*/

int	malloc_size(char *name)
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
		ret++;
	if (closedir(directory) == -1)
		return (-1);
	return (ret);
}
