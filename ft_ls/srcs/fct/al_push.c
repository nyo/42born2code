/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 22:21:40 by anyo              #+#    #+#             */
/*   Updated: 2017/06/08 20:18:10 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	dirlist(), errlist() & othlist() all creates array of strings, containing
**	respectively all the directories, unexisting files,
**	and other type of files.
**	return value:
**		NULL - ERROR! malloc()
**		The fulfilled array of strings - no more data to add, OK!
*/

static char	**dirlist(int argc, char **clean, t_opt opt)
{
	struct stat	*stt;
	char		**dirlst;
	int			i;
	int			j;

	i = -1;
	j = 0;
	if (!(stt = malloc(sizeof(struct stat))))
		return (NULL);
	if (!(dirlst = malloc(sizeof(char *) * argc)))
		return (NULL);
	while (*(clean + ++i))
		if (stat(*(clean + i), stt) != -1)
			if (S_ISDIR(stt->st_mode))
				if (!(*(dirlst + j++) = ft_strdup(*(clean + i))))
					return (NULL);
	*(dirlst + j) = NULL;
	ft_arrsort(dirlst, j);
	free(stt);
	if (opt.opt_t == 1)
		arr_sort_time(dirlst, "", opt);
	if (opt.opt_r == 1)
		ft_arrrev(dirlst);
	return (dirlst);
}

static char	**errlist(int argc, char **clean)
{
	struct stat	*stt;
	char		**errlst;
	int			i;
	int			j;

	i = -1;
	j = 0;
	if (!(stt = malloc(sizeof(struct stat))))
		return (NULL);
	if (!(errlst = malloc(sizeof(char *) * argc)))
		return (NULL);
	while (*(clean + ++i))
		if (stat(*(clean + i), stt) == -1)
			if (!(*(errlst + j++) = ft_strdup(*(clean + i))))
				return (NULL);
	*(errlst + j) = NULL;
	ft_arrsort(errlst, j);
	free(stt);
	return (errlst);
}

static char	**othlist(int argc, char **clean, t_opt opt)
{
	struct stat	*stt;
	char		**othlst;
	int			i;
	int			j;

	i = -1;
	j = 0;
	if (!(stt = malloc(sizeof(struct stat))))
		return (NULL);
	if (!(othlst = malloc(sizeof(char *) * argc)))
		return (NULL);
	while (*(clean + ++i))
		if (stat(*(clean + i), stt) != -1)
			if (!S_ISDIR(stt->st_mode))
				if (!(*(othlst + j++) = ft_strdup(*(clean + i))))
					return (NULL);
	*(othlst + j) = NULL;
	ft_arrsort(othlst, j);
	free(stt);
	if (opt.opt_t == 1)
		arr_sort_time(othlst, "", opt);
	if (opt.opt_r == 1)
		ft_arrrev(othlst);
	return (othlst);
}

/*
**	pushlst() copies the parameters in the right order.
**	return value:
**		NULL - ERROR! malloc()
**		The filled array of strings - no more data to add, OK!
*/

static char	**pushlst(char **errlst, char **othlst, char **dirlst, int argc)
{
	char	**fnllst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(fnllst = malloc(sizeof(char *) * argc)))
		return (NULL);
	while (*(errlst + i))
		if (!(*(fnllst + j++) = ft_strdup(*(errlst + i++))))
			return (NULL);
	i = 0;
	while (*(othlst + i))
		if (!(*(fnllst + j++) = ft_strdup(*(othlst + i++))))
			return (NULL);
	i = 0;
	while (*(dirlst + i))
		if (!(*(fnllst + j++) = ft_strdup(*(dirlst + i++))))
			return (NULL);
	*(fnllst + j) = NULL;
	return (fnllst);
}

/*
**	al_push() sorts the list of the entered parameters, as ls(1) does.
*/

char		**al_push(int argc, char **argv, t_opt opt)
{
	char	**arglst;
	char	**errlst;
	char	**othlst;
	char	**dirlst;
	char	**clean;

	if (!(clean = al_clean(argc, argv)))
		return (NULL);
	if (!(errlst = errlist(argc, clean)))
		return (NULL);
	if (!(othlst = othlist(argc, clean, opt)))
		return (NULL);
	if (!(dirlst = dirlist(argc, clean, opt)))
		return (NULL);
	if (!(arglst = pushlst(errlst, othlst, dirlst, argc)))
		return (NULL);
	ft_arrfree(errlst);
	ft_arrfree(othlst);
	ft_arrfree(dirlst);
	ft_arrfree(clean);
	ft_arrrev(arglst);
	return (arglst);
}
