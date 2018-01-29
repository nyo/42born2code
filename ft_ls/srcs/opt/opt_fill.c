/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:53:43 by anyo              #+#    #+#             */
/*   Updated: 2017/06/22 17:33:59 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	opt_error() prints the right usage if an option is invalid.
**	if only I had done ft_printf before...
*/

static void	opt_error(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	ft_putstr_fd(*argv, 2);
	ft_putstr_fd(": illegal option -- ", 2);
	while (opt_is(*(argv + i)) != 2)
		i++;
	while (ISVLDLTR(argv[i][j]))
		j++;
	ft_putchar_fd(argv[i][j], 2);
	ft_putstr_fd("\nusage: ", 2);
	ft_putstr_fd(*argv, 2);
	ft_putendl_fd(" [-Ralrt] [file ...]", 2);
}

/*
**	opt_init() initializes the structure called `t_opt` to the default values.
*/

static void	opt_init(t_opt *p)
{
	p->opt_l = 0;
	p->opt_a = 0;
	p->opt_r = 0;
	p->opt_t = 0;
	p->opt_br = 0;
	p->max_pw = 0;
	p->max_gr = 0;
	p->max_nl = 0;
	p->max_sz = 0;
}

/*
**	opt_flag() sets the content of the structure called `t_opt` to
**	the correct value.
*/

static void	opt_flag(char *c, t_opt *p)
{
	if (ft_strchr(c, 'l'))
		p->opt_l = 1;
	if (ft_strchr(c, 'a'))
		p->opt_a = 1;
	if (ft_strchr(c, 'r'))
		p->opt_r = 1;
	if (ft_strchr(c, 't'))
		p->opt_t = 1;
	if (ft_strchr(c, 'R'))
		p->opt_br = 1;
}

/*
**	opt_fill() fills the structure called `t_opt`.
**	return value:
**		0 - ERROR! invalid option
**		1 - no more option to add, OK!
*/

int			opt_fill(int argc, char **argv, t_opt *opt)
{
	int	i;

	i = 1;
	opt_init(opt);
	if (opt_is(*(argv + i)) == 1)
	{
		while (i < argc && opt_is(*(argv + i)) == 1)
		{
			opt_flag(*(argv + i), opt);
			i++;
		}
	}
	if (i < argc && opt_is(*(argv + i)) == 2)
	{
		opt_error(argv);
		return (0);
	}
	return (1);
}
