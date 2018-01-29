/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_lst_ls_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:58:00 by anyo              #+#    #+#             */
/*   Updated: 2017/06/07 21:17:48 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	sort_fltr() sorts/reverse filelist depending of -t & -r
*/

static void	sort_fltr(char **filelist, char *dirname, t_opt opt)
{
	if (opt.opt_t == 1)
		arr_sort_time(filelist, dirname, opt);
	if (opt.opt_r == 1)
		ft_arrrev(filelist);
}

/*
**	ret_ls_1() is a simple implementation of `ls -1`.
**	It fills the filelist.
**	return value:
**		0 - ERROR! malloc() or closedir()
**		1 - no more data to add, OK!
*/

int			ret_lst_ls_1(char **filelist, char *dirname, t_opt opt)
{
	struct dirent	*file_info;
	DIR				*directory;
	int				i;

	i = 0;
	directory = NULL;
	file_info = NULL;
	if ((directory = opendir(dirname)))
	{
		while ((file_info = readdir(directory)))
			if (!(*(filelist + i++) = ft_strdup(file_info->d_name)))
				return (0);
		if (closedir(directory) == -1)
			return (0);
	}
	else
	{
		if (!(*(filelist + i++) = ft_strdup(dirname)))
			return (0);
	}
	*(filelist + i) = NULL;
	ft_arrsort(filelist, i);
	sort_fltr(filelist, dirname, opt);
	return (1);
}
