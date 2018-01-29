/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_pl_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 21:14:56 by anyo              #+#    #+#             */
/*   Updated: 2017/06/08 21:30:54 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	ret_pl_values() fills the `max*` part of the structure called `t_opt`.
*/

void		ret_pl_values(t_opt *opt, t_ret *ret)
{
	opt->max_pw = 0;
	opt->max_gr = 0;
	opt->max_nl = 0;
	opt->max_sz = 0;
	opt->blksize = 0;
	while (ret)
	{
		if (!ret->error && ret->name)
		{
			opt->max_pw = opt->max_pw > (int)ft_strlen(ret->pw_name) ?
				opt->max_pw : ft_strlen(ret->pw_name);
			opt->max_gr = opt->max_gr > (int)ft_strlen(ret->gr_name) ?
				opt->max_gr : ft_strlen(ret->gr_name);
			opt->max_sz = opt->max_sz > (int)ft_strlen(ret->size) ?
				opt->max_sz : ft_strlen(ret->size);
			opt->max_nl = opt->max_nl > (int)ft_intlen(ret->nlink) ?
				opt->max_nl : ft_intlen(ret->nlink);
			opt->blksize = opt->blksize + ret->blksize;
		}
		ret = ret->next;
	}
}
