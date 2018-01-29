/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_print_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:00:34 by anyo              #+#    #+#             */
/*   Updated: 2017/06/22 17:33:32 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	ret_ask_if_print() returns if ffod_dirname is a hidden directory or not,
**	so we know if the whole directory (along with its name) must be printed.
**	return value:
**		0 - ffod_dirname is hidden, OK!
**		1 - ffod_dirname isn't hidden, OK!
*/

static int	ret_ask_if_print(char *ffod_dirname)
{
	int	i;

	i = -1;
	while (*(ffod_dirname + ++i))
		if (*(ffod_dirname + i) == '/' &&
				*(ffod_dirname + i + 1) && *(ffod_dirname + i + 2))
			if (*(ffod_dirname + i + 1) == '.' &&
					*(ffod_dirname + i + 2) != '.')
				return (0);
	return (1);
}

/*
**	ret_print_jftn() helps ret_print_l_or_not(), and is here
**	just for the norminette. (:
*/

static void	ret_print_jftn(t_ret *ret, t_opt opt)
{
	int	i;

	i = ft_intlen(ret->nlink) - 1;
	while (++i < opt.max_nl)
		ft_putchar(' ');
	ft_putnbr(ret->nlink);
	ft_putchar(' ');
	ft_putstr(ret->pw_name);
	i = ft_strlen(ret->pw_name) - 3;
	while (++i < opt.max_pw)
		ft_putchar(' ');
	ft_putstr(ret->gr_name);
	i = ft_strlen(ret->gr_name) - 3;
	while (++i < opt.max_gr)
		ft_putchar(' ');
	i = ft_strlen(ret->size) - 1;
	while (++i < opt.max_sz)
		ft_putchar(' ');
}

/*
**	ret_print_l_or_not() formats/prints depending of which options are on.
*/

static void	ret_print_l_or_not(t_ret *ret, t_opt opt)
{
	char	*tmp;

	if (!(tmp = format_date(ret->date)))
		return ;
	if (!opt.opt_l)
		ft_putendl(ret->name);
	else
	{
		ft_putstr(ret->modes);
		ft_putstr("  ");
		ret_print_jftn(ret, opt);
		ft_putstr(ret->size);
		ft_putchar(' ');
		ft_putstr(tmp);
		ft_putchar(' ');
		ft_putendl(*ret->modes == 'l' ? ret->lname : ret->name);
	}
	free(tmp);
}

/*
**	ret_print_node_ctt() prints the content of the current argument.
**	return value:
**		Print value - OK!
*/

static int	ret_print_node_ctt(t_ret *r, t_opt o, int len, int print)
{
	if (len && r->ffod_dirname)
	{
		if (!o.opt_a)
			print = ret_ask_if_print(r->ffod_dirname);
		if (print)
		{
			ft_putendl(ft_strjoin("\n", ft_strjoin(r->ffod_dirname, ":")));
			if (o.opt_l)
				ft_putendl(ft_strjoin("total ", ft_itoa(o.blksize)));
		}
	}
	if (print && r->error)
		ft_putendl_fd(ft_strjoin(ft_strjoin(ft_strjoin("ft_ls: ", r->name),
						": "), r->error), 2);
	else if (print && r->name)
	{
		if (!(ISHIDDEN(*r->name)))
			ret_print_l_or_not(r, o);
		else
		{
			if (o.opt_a)
				ret_print_l_or_not(r, o);
		}
	}
	return (print);
}

/*
**	ret_print_node() prints the content of every nodes of the linked list
**	related to the current argument. It is formatted exactly as `ls(1)` does,
**	depending of which options are on.
*/

void		ret_print_node(t_ret *ret, t_arg *arg, t_opt opt, int arg_len)
{
	int	ret_len;
	int	caniprint;

	ret_len = 0;
	caniprint = 1;
	if ((ISDIR(*arg->modes)) == 1)
	{
		if (opt.opt_l && arg_len == 1)
			ft_putendl(ft_strjoin("total ", ft_itoa(opt.blksize)));
		else if (arg_len > 1)
		{
			ft_putendl(ft_strjoin(arg->name, ":"));
			if (opt.opt_l)
				ft_putendl(ft_strjoin("total ", ft_itoa(opt.blksize)));
		}
	}
	while (ret)
	{
		caniprint = ret_print_node_ctt(ret, opt, ret_len, caniprint);
		ret = ret->next;
		ret_len++;
	}
}
