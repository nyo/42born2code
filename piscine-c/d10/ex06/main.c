/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:06:04 by anyo              #+#    #+#             */
/*   Updated: 2016/08/22 16:53:27 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "protodo.h"

int		g_i;
int		g_val1;
int		g_val2;
char	*g_sign;

int		main(int argc, char **argv)
{
	void	(*fct[5])(int, int);

	if (argc == 4)
	{
		g_i = -1;
		g_val1 = ((ft_is_nb(argv[1]) == 0) ? 0 : ft_atoi(argv[1]));
		g_val2 = ((ft_is_nb(argv[3]) == 0) ? 0 : ft_atoi(argv[3]));
		fct[0] = &ft_add;
		fct[1] = &ft_sub;
		fct[2] = &ft_mul;
		fct[3] = &ft_div;
		fct[4] = &ft_mod;
		g_sign = "+-*/%";
		if (ft_is_op(argv[2]) == 1)
		{
			while (g_i++ < 5)
				if (argv[2][0] == g_sign[g_i])
					(*fct[g_i])(g_val1, g_val2);
		}
		else
			ft_putstr("0\n");
	}
	return (0);
}
