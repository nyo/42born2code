/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_fill_ls_1_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 21:13:54 by anyo              #+#    #+#             */
/*   Updated: 2017/06/19 20:23:57 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	ret_fill_data_stt() fills the linked list called `t_ret`
**	with data from `struct stat *stt`.
**	return value:
**		0 - ERROR! format_mode(), format_size() or malloc()
**		1 - no more data to add, OK!
*/

static int	ret_fill_data_stt_n(t_ret *elm, struct stat *stt, char *t, char *f)
{
	if (!(elm->modes = format_mode(stt->st_mode)))
		return (0);
	if (!(elm->size = format_size(stt->st_mode, stt->st_rdev, stt->st_size)))
		return (0);
	if (S_ISLNK(stt->st_mode))
	{
		if (!(elm->lname = format_lname(f, t, stt->st_size)))
			return (0);
	}
	else
		elm->lname = NULL;
	elm->blksize = stt->st_blocks;
	elm->nlink = stt->st_nlink;
	elm->date = stt->st_mtime;
	elm->error = NULL;
	return (1);
}

static int	ret_fill_data_stt(t_ret *elm, struct stat *stt, char *d, char *f)
{
	struct passwd	*usr;
	struct group	*grp;
	char			*tmp1;
	char			*tmp2;

	if (!(usr = getpwuid(stt->st_uid)))
		return (0);
	if (!(grp = getgrgid(stt->st_gid)))
		return (0);
	if (!(tmp1 = ft_strjoin(d, "/")))
		return (0);
	if (!(tmp2 = ft_strjoin(tmp1, f)))
		return (0);
	if (!(ret_fill_data_stt_n(elm, stt, tmp2, f)))
		return (0);
	elm->pw_name = usr->pw_name;
	elm->gr_name = grp->gr_name;
	free(tmp1);
	free(tmp2);
	return (1);
}

/*
**	ret_fill_data() fills the linked list called `t_ret`
**	with the data it needs.
**	return value:
**		0 - ERROR! malloc(), getpwuid(), getgrgid() or ret_fill_data_stt()
**		1 - no more data to add, OK!
*/

static int	ret_fill_data(t_ret *elm, char *dirname, char *filename)
{
	struct stat		*stt;
	char			*tmp1;
	char			*tmp2;

	if (!(stt = malloc(sizeof(struct stat))))
		return (0);
	if (!(tmp1 = ft_strjoin(dirname, "/")))
		return (0);
	if (!(tmp2 = ft_strjoin(tmp1, filename)))
		return (0);
	if (!(elm->name = ft_strdup(filename)))
		return (0);
	elm->ffod_dirname = NULL;
	if (lstat(tmp2, stt) != -1)
	{
		if (!(ret_fill_data_stt(elm, stt, dirname, filename)))
			return (0);
	}
	else
		elm->error = strerror(errno);
	free(tmp1);
	free(tmp2);
	free(stt);
	return (1);
}

/*
**	ret_fill_ls_1() fills the linked list called `t_ret`
**	as calling `ls -1` would've do.
**	return value:
**		0 - ERROR! malloc() or ret_fill_data()
**		1 - no more data to add, OK!
*/

int			ret_fill_ls_1(t_ret **ret, char *dirname, t_opt opt)
{
	char			**fl;
	t_ret			*elm;
	int				i;

	i = 0;
	if (!(fl = malloc(sizeof(char *) * (malloc_size(dirname) + 1))))
		return (0);
	if (!(ret_lst_ls_1(fl, dirname, opt)))
		return (0);
	while (*(fl + i))
	{
		if (!(elm = malloc(sizeof(t_ret))))
			return (0);
		if (!(ret_fill_data(elm, dirname, *(fl + i))))
			return (0);
		elm->next = *ret;
		*ret = elm;
		i++;
	}
	ft_arrfree(fl);
	return (1);
}
