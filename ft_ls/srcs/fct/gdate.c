/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdate.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:07:10 by anyo              #+#    #+#             */
/*   Updated: 2017/06/08 20:13:52 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	free_ntt() frees tmp1, tmp2, stt.
*/

static void	free_ntt(char *tmp1, char *tmp2, struct stat *stt)
{
	free(tmp1);
	free(tmp2);
	free(stt);
}

/*
**	gdate() returns the exact date of a given file.
**	return value:
**		0 - ERROR!
**		1 or greater - date of the file, OK!
*/

int			gdate(char *file, char *dir, t_opt opt)
{
	struct stat	*stt;
	time_t		date;
	char		*tmp1;
	char		*tmp2;

	if (!(stt = malloc(sizeof(struct stat))))
		return (0);
	if (!(tmp1 = ft_strjoin(dir, ft_strlen(dir) > 0 ? "/" : "")))
		return (0);
	if (!(tmp2 = ft_strjoin(tmp1, file)))
		return (0);
	if (opt.opt_l == 1)
	{
		if (lstat(tmp2, stt) == -1)
			return (0);
	}
	else
	{
		if (stat(tmp2, stt) == -1)
			return (0);
	}
	date = stt->st_mtime;
	free_ntt(tmp1, tmp2, stt);
	return (date);
}
