/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:28:58 by anyo              #+#    #+#             */
/*   Updated: 2017/06/22 17:31:46 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	ret_free_list() frees every node of `t_ret` linked list.
*/

static void	ret_free_list(t_ret **lst)
{
	void	*ptr;

	while (*lst)
	{
		ptr = (*lst)->next;
		if (!((*lst)->error))
		{
			if (((*lst)->ffod_dirname))
				free(((*lst)->ffod_dirname));
			else
			{
				free((*lst)->name);
				free((*lst)->modes);
				free((*lst)->lname);
				free((*lst)->size);
			}
		}
		free(*lst);
		*lst = ptr;
	}
	free(ptr);
}

/*
**	arg_error() prints the correct error as ls(1) does.
*/

static int	arg_error(t_arg *arg)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(arg->name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(arg->error, 2);
	return (1);
}

/*
**	return_value() sets the return value for the whole program.
**	return value:
**		0 - OK!
**		1 - ERROR!
*/

static int	return_value(t_ret *ret)
{
	while (ret)
	{
		if (ret->error)
			return (1);
		ret = ret->next;
	}
	return (0);
}

/*
**	ret_fill_ntt() fills the linked list called `t_ret`,
**	then prints its content.
**	return value:
**		-1 - ERROR! malloc()
**		1 - no more thing to do, returns `r`, OK!
*/

static int	ret_fill_ntt(t_ret *ret, t_arg *arg, t_opt opt, int total_len)
{
	if ((ISDIR(*arg->modes)) == 0)
	{
		if (!(ret_fill_notdir(&ret, arg->name)))
			return (-1);
	}
	else
	{
		if (opt.opt_br == 1)
		{
			if (!(ret_fill_ls_br(&ret, opt, arg->name)))
				return (-1);
		}
		else
		{
			if (!(ret_fill_ls_1(&ret, arg->name, opt)))
				return (-1);
		}
		ret_reverse_lst(&ret);
	}
	ret_pl_values(&opt, ret);
	ret_print_node(ret, arg, opt, total_len);
	total_len = return_value(ret);
	ret_free_list(&ret);
	return (total_len);
}

/*
**	ret_fill() fills the linked list called `t_ret`,
**	then prints its content.
**	return value:
**		-1 - ERROR! malloc()
**		0 or higher - no more thing to do, OK!
*/

int			ret_fill(t_arg *arg, t_opt opt)
{
	t_ret	*ret;
	int		live_len;
	int		total_len;
	int		tmp;
	int		rv;

	rv = 0;
	ret = NULL;
	live_len = 0;
	total_len = arg_len(arg);
	while (arg)
	{
		if (!arg->error)
		{
			ft_putstr((live_len++ > 0 && ISDIR(*arg->modes)) ? "\n" : NULL);
			if ((tmp = ret_fill_ntt(ret, arg, opt, total_len)) == -1)
				return (-1);
			if (tmp == 1)
				rv = 1;
		}
		else
			rv = arg_error(arg);
		arg = arg->next;
	}
	return (rv);
}
