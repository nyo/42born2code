/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_lst_ls_br.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 21:10:07 by anyo              #+#    #+#             */
/*   Updated: 2017/06/19 20:57:29 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	is_okx() indicates if `filename` is a directory.
**	(in case of links, readdir() returns data about the area
**	pointed by the link, we don't want that.)
**	return value:
**		-1 - ERROR! malloc() or lstat()
**		0 - `filename` is not a dir, OK!
**		1 - `filename` is a dir, OK!
*/

static int	is_okx(char *new_name, char *filename)
{
	struct stat	*stt;
	char		*tmp;
	int			ret;

	if (ft_strcmp(filename, ".") == 0 || ft_strcmp(filename, "..") == 0)
		return (0);
	if (!(stt = malloc(sizeof(struct stat))))
		return (-1);
	if (!(tmp = ft_strjoin(new_name, filename)))
		return (-1);
	if (lstat(tmp, stt) == -1)
		return (-1);
	ret = S_ISDIR(stt->st_mode) ? 1 : 0;
	free(stt);
	free(tmp);
	return (ret);
}

/*
**	i_len() returns how many field of the list of char * `fl`
**	has been filled.
**	return value:
**		-1 - ERROR! malloc() or closedir()
**		0 or greater - `i` value, OK!
*/

static int	i_len(char *dirname)
{
	struct dirent	*file_info;
	DIR				*directory;
	char			*newname;
	int				i;

	i = 0;
	if (!(newname = ft_strjoin(dirname, "/")))
		return (-1);
	if ((directory = opendir(dirname)))
	{
		while ((file_info = readdir(directory)))
			if (is_okx(newname, file_info->d_name) != -1)
				i++;
		if (closedir(directory) == -1)
			return (-1);
	}
	free(newname);
	return (i);
}

/*
**	ret_fill_filelist_ntt() fills both `filelist` and `dirlist` with data.
**	return value:
**		-1 - ERROR! malloc(), opendir() or closedir()
**		0 or greater - `j` value, no data left to add, OK!
*/

static int	ret_fill_filelist_ntt(char ***fl, char **dl, DIR *dir, char *dn)
{
	struct dirent	*file_info;
	char			*newname;
	int				j;

	j = 0;
	if (!(newname = ft_strjoin(dn, "/")))
		return (0);
	while ((file_info = readdir(dir)))
	{
		if (is_okx(newname, file_info->d_name) != -1)
		{
			if (!(*(*fl)++ = ft_strdup(file_info->d_name)))
				return (-1);
			if (is_okx(newname, file_info->d_name) == 1)
			{
				if (!(*(dl + j) = ft_strjoin(newname, file_info->d_name)))
					return (-1);
				j++;
			}
		}
	}
	if (closedir(dir) == -1)
		return (-1);
	free(newname);
	return (j);
}

/*
**	ret_fill_filelist() fills both `filelist` and `dirlist` with data.
**	return value:
**		0 - ERROR! malloc(), opendir() or closedir()
**		1 or greater - `i` value, no data left to add, OK!
*/

static int	ret_fill_filelist(char **fl, char **dl, char *dirname, t_opt opt)
{
	DIR		*directory;
	int		j;

	j = 0;
	if ((directory = opendir(dirname)))
	{
		if ((j = ret_fill_filelist_ntt(&fl, dl, directory, dirname)) == -1)
			return (0);
	}
	else
	{
		if (!(*fl++ = ft_strdup(dirname)))
			return (0);
	}
	*fl = NULL;
	*(dl + j) = NULL;
	ft_arrsort_i(fl, i_len(dirname));
	if (opt.opt_t == 1)
		arr_sort_time_i(fl, dirname, opt, i_len(dirname));
	if (opt.opt_r == 1)
		ft_arrrev_i(fl, i_len(dirname));
	return (1);
}

/*
**	ret_ls_br() is a simple implementation of `ls -R`.
**	It fills the filelist.
**	return value:
**		0 - ERROR! malloc(), opendir() or closedir()
**		1 - no more data to add, OK!
*/

int			ret_lst_ls_br(char **filelist, char *dirname, t_opt opt)
{
	char			**dirlist;
	int				i;

	i = 0;
	while (*filelist)
		filelist++;
	if (!(*filelist++ = ft_strjoin(">FFOD<", dirname)))
		return (0);
	if (!(dirlist = malloc(sizeof(char *) * (MALLOCSIZE + 1))))
		return (0);
	if (!(ret_fill_filelist(filelist, dirlist, dirname, opt)))
		return (0);
	ft_arrsort(dirlist, ft_arrlen(dirlist));
	if (opt.opt_t == 1)
		arr_sort_time(dirlist, "", opt);
	if (opt.opt_r == 1)
		ft_arrrev(dirlist);
	while (*(dirlist + i))
	{
		ret_lst_ls_br(filelist, *(dirlist + i), opt);
		i++;
	}
	ft_arrfree(dirlist);
	return (1);
}
