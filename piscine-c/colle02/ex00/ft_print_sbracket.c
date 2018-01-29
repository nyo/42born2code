/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sbracket.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:59:24 by anyo              #+#    #+#             */
/*   Updated: 2016/08/21 21:05:37 by bin0me           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "protocolle.h"

void	ft_prt_1(void)
{
	ft_putstr("[colle-02] [1] [1] || ");
	ft_putstr("[colle-03] [1] [1] || ");
	ft_putstr("[colle-04] [1] [1]");
}

void	ft_prt_2(int b)
{
	ft_putstr("[colle-02] [1] [");
	ft_putnbr(b);
	ft_putstr(" || [colle-04] [1] [");
	ft_putnbr(b);
	ft_putstr("]");
}

void	ft_prt_3(int a)
{
	ft_putstr("[colle-02] [");
	ft_putnbr(a);
	ft_putstr("] [1] || [colle-04] [1");
	ft_putnbr(a);
	ft_putstr("] [1]");
}

void	ft_print_sbracket(char *str, int a, int b)
{
	int i;

	i = 0;
	if (ft_check_size(str) == 0)
	{
		ft_putstr("[");
		ft_wich_colle(ft_keep_s(str), ft_keep_e(str));
		ft_putstr("] [");
		ft_putnbr(a);
		ft_putstr("] [");
		ft_putnbr(b);
		ft_putstr("]");
	}
	else if (ft_check_size(str) == 3)
		ft_prt_1();
	else if (ft_check_size(str) == 2)
		ft_prt_2(b);
	else if (ft_check_size(str) == 1)
		ft_prt_3(a);
	else if (ft_check_size(str) == 4)
		ft_putstr("[colle-00] [1] [1]");
	else if (ft_check_size(str) == 5)
		ft_putstr("[colle-01] [1] [1]");
	else if (ft_check_size(str) == 6)
		ft_putstr("[colle-00] [2] [1]");
}
