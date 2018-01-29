/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_fill_ls_br.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:47:10 by anyo              #+#    #+#             */
/*   Updated: 2017/06/22 18:31:46 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ret_fill_4(char *filename, char *tmp2, t_ret *elm, struct stat *stt)
{
	if (!(elm->modes = format_mode(stt->st_mode)))
		return (0);
	if (!(elm->size = format_size(stt->st_mode, stt->st_rdev, stt->st_size)))
		return (0);
	if (S_ISLNK(stt->st_mode))
	{
		if (!(elm->lname = format_lname(filename, tmp2, stt->st_size)))
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

static int	ret_fill_3(char *nn, char *filename, t_ret *elm, struct stat *stt)
{
	struct passwd	*usr;
	struct group	*grp;
	char			*tmp1;
	char			*tmp2;

	if (!(usr = getpwuid(stt->st_uid)))
		return (0);
	if (!(grp = getgrgid(stt->st_gid)))
		return (0);
	if (!(tmp1 = ft_strjoin(nn, "/")))
		return (0);
	if (!(tmp2 = ft_strjoin(tmp1, filename)))
		return (0);
	if ((ret_fill_4(filename, tmp2, elm, stt)) == 0)
		return (0);
	elm->pw_name = usr->pw_name;
	elm->gr_name = grp->gr_name;
	free(tmp1);
	free(tmp2);
	return (1);
}

static int	ret_fill_2(char *newname, char *filename, t_ret *elm)
{
	struct stat		*stt;
	char			*tmp1;
	char			*tmp2;

	if (!(stt = malloc(sizeof(struct stat))))
		return (0);
	if (!(tmp1 = ft_strjoin(newname, "/")))
		return (0);
	if (!(tmp2 = ft_strjoin(tmp1, filename)))
		return (0);
	if (!(elm->name = ft_strdup(filename)))
		return (0);
	if (lstat(tmp2, stt) != -1)
	{
		if ((ret_fill_3(newname, filename, elm, stt)) == 0)
			return (0);
	}
	else
		elm->error = strerror(errno);
	free(stt);
	free(tmp1);
	free(tmp2);
	return (1);
}

static int	ret_fill_1(char **filelist, char **newname, int i, t_ret *elm)
{
	if (ft_strstr(*(filelist + i), ">FFOD<"))
	{
		if (*newname)
			free(*newname);
		if (!(*newname = ft_strdup(*(filelist + i) + 6)))
			return (0);
		if (!(elm->ffod_dirname = ft_strdup(*newname)))
			return (0);
		free(*(filelist + i));
		i++;
	}
	else
		elm->ffod_dirname = NULL;
	if (*(filelist + i) && !(ft_strstr(*(filelist + i), ">FFOD<")))
	{
		if ((ret_fill_2(*newname, *(filelist + i), elm)) == 0)
			return (0);
	}
	else if (*(filelist + i))
		elm->name = NULL;
	free(*(filelist + i));
	i++;
	return (i);
}

int			ret_fill_ls_br(t_ret **ret, t_opt opt, char *dirname)
{
	char			**filelist;
	char			*newname;
	int				i;
	t_ret			*elm;

	i = 0;
	newname = NULL;
	filelist = NULL;
	if (!(filelist = malloc(sizeof(char *) * (MALLOCSIZE + 1))))
		return (0);
	if ((ret_lst_ls_br(filelist, dirname, opt)) == 0)
		return (0);
	while (*(filelist + i))
	{
		if (!(elm = malloc(sizeof(t_ret))))
			return (0);
		if ((i = ret_fill_1(filelist, &newname, i, elm)) == 0)
			return (0);
		elm->next = *ret;
		*ret = elm;
	}
	free(newname);
	return (1);
}
