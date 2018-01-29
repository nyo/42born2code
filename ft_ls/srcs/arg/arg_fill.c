/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 23:09:38 by anyo              #+#    #+#             */
/*   Updated: 2017/06/07 23:09:41 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	arg_fill_exarg(_n)() fills the linked list called `t_arg`,
**	if there is at least a file/directory/... specified.
**	return value:
**		0 - ERROR! malloc() or lstat()
**		1 - no more data to add, OK!
*/

static int	arg_fill_struct_n(char *n, t_arg *elm, t_opt opt, struct stat *stt)
{
	elm->error = NULL;
	if (stat(n, stt) == -1)
		elm->error = strerror(errno);
	if (opt.opt_l == 1 || !S_ISDIR(stt->st_mode))
		if (lstat(n, stt) == -1)
			elm->error = strerror(errno);
	if (!(elm->name = ft_strdup(n)))
		return (0);
	if (!elm->error)
		if (!(elm->modes = format_mode(stt->st_mode)))
			return (0);
	return (1);
}

static int	arg_fill_struct(char **lst, t_arg **arg, t_opt opt)
{
	struct stat		*stt;
	t_arg			*elm;
	int				i;

	i = 0;
	elm = NULL;
	while (*(lst + i))
	{
		if (!(elm = malloc(sizeof(t_arg))))
			return (0);
		if (!(stt = malloc(sizeof(struct stat))))
			return (0);
		if (!(arg_fill_struct_n(*(lst + i), elm, opt, stt)))
			return (0);
		elm->next = *arg;
		*arg = elm;
		free(stt);
		i++;
	}
	return (1);
}

/*
**	arg_fill() fills the linked list called `t_arg`.
**	return value:
**		0 - ERROR! malloc() or lstat()
**		1 - no more data to add, OK!
*/

int			arg_fill(char **rlist, t_arg **arg, t_opt opt)
{
	char	**noarg;
	t_arg	*elm;
	int		er;

	er = 0;
	elm = NULL;
	if (!(noarg = malloc(sizeof(char *) * 2)))
		return (0);
	if (!(*(noarg + 0) = ft_strdup(".")))
		return (0);
	*(noarg + 1) = NULL;
	er = arg_fill_struct(ft_arrlen(rlist) == 0 ? noarg : rlist, &elm, opt);
	*arg = elm;
	ft_arrfree(noarg);
	return (er);
}
