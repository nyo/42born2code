/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_fill_notdir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:44:29 by anyo              #+#    #+#             */
/*   Updated: 2017/06/08 18:52:25 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	ret_fill_stt() fills the 'stt part'.
**	return value:
**		0 - ERROR! format_mode(), format_size() or format_lname()
**		1 - no more data to add, OK!
*/

static int	ret_fill_stt(t_ret *elm, struct stat *stt, char *filename)
{
	struct passwd	*usr;
	struct group	*grp;

	if (!(usr = getpwuid(stt->st_uid)))
		return (0);
	if (!(grp = getgrgid(stt->st_gid)))
		return (0);
	if (!(elm->modes = format_mode(stt->st_mode)))
		return (0);
	if (!(elm->size = format_size(stt->st_mode, stt->st_rdev, stt->st_size)))
		return (0);
	if (S_ISLNK(stt->st_mode))
	{
		if (!(elm->lname = format_lname(filename, filename, stt->st_size)))
			return (0);
	}
	else
		elm->lname = NULL;
	elm->blksize = stt->st_blocks;
	elm->nlink = stt->st_nlink;
	elm->date = stt->st_mtime;
	elm->pw_name = usr->pw_name;
	elm->gr_name = grp->gr_name;
	elm->error = NULL;
	return (1);
}

/*
**	ret_fill_notdir() fills the linked list called `t_ret`.
**	return value:
**		0 - ERROR! malloc(), lstat(), getpwuid(), getgrgid() or ret_fill_stt()
**		1 - no more data to add, OK!
*/

int			ret_fill_notdir(t_ret **ret, char *filename)
{
	struct stat		*stt;
	t_ret			*elm;

	if (!(elm = malloc(sizeof(t_ret))))
		return (0);
	if (!(stt = malloc(sizeof(struct stat))))
		return (0);
	if (!(elm->name = ft_strdup(filename)))
		return (0);
	elm->ffod_dirname = NULL;
	if (lstat(filename, stt) != -1)
	{
		if (!(ret_fill_stt(elm, stt, filename)))
			return (0);
	}
	else
		elm->error = strerror(errno);
	free(stt);
	elm->next = NULL;
	*ret = elm;
	return (1);
}
