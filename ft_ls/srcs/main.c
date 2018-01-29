/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:41:22 by anyo              #+#    #+#             */
/*   Updated: 2017/06/22 17:35:22 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	free_tt() frees all the `t_arg` linked list.
*/

static void	free_tt(t_arg **lst, char **arglst)
{
	void	*ptr;

	while (*lst)
	{
		ptr = (*lst)->next;
		if (!(*lst)->error)
			free((*lst)->modes);
		free((*lst)->name);
		free(*lst);
		*lst = ptr;
	}
	free(ptr);
	ft_arrfree(arglst);
}

/*
**	main() ¿?
*/

int			main(int argc, char **argv)
{
	char	**arglst;
	t_arg	*arg;
	t_opt	opt;
	int		rv;

	rv = 1;
	arglst = NULL;
	if (argc == 1)
	{
		if (ls_basic(".") == 0)
			exit(EXIT_FAILURE);
	}
	else
	{
		if (opt_fill(argc, argv, &opt) == 0)
			exit(EXIT_FAILURE);
		if (!(arglst = al_push(argc, argv, opt)))
			exit(EXIT_FAILURE);
		if (arg_fill(arglst, &arg, opt) == 0)
			exit(EXIT_FAILURE);
		if ((rv = ret_fill(arg, opt)) == -1)
			exit(EXIT_FAILURE);
		free_tt(&arg, arglst);
	}
	exit(rv == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
