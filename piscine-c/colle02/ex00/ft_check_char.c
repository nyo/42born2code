/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bin0me                                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 12:37:37 by bin0me            #+#    #+#             */
/*   Updated: 2016/08/21 21:05:38 by bin0me           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "protocolle.h"

int		ft_ck_fl(char *s1)
{
	char *possib1;
	char *possib2;
	char *possib3;
	char *possib4;
	char *possib5;

	possib1 = "o-o";
	possib2 = "/*\\";
	possib3 = "ABA";
	possib4 = "ABC";
	possib5 = "ABC";
	if (ft_strcmp(s1, possib1) == 0
		|| ft_strcmp(s1, possib2) == 0
		|| ft_strcmp(s1, possib3) == 0
		|| ft_strcmp(s1, possib4) == 0
		|| ft_strcmp(s1, possib5) == 0)
		return (1);
	else
		return (0);
}

int		ft_ck_ll(char *s2)
{
	char *possib1;
	char *possib2;
	char *possib3;
	char *possib4;
	char *possib5;

	possib1 = "o-o";
	possib2 = "\\*/";
	possib3 = "CBC";
	possib4 = "ABC";
	possib5 = "CBA";
	if (ft_strcmp(s2, possib1) == 0
		|| ft_strcmp(s2, possib2) == 0
		|| ft_strcmp(s2, possib3) == 0
		|| ft_strcmp(s2, possib4) == 0
		|| ft_strcmp(s2, possib5) == 0)
		return (1);
	else
		return (0);
}

int		ft_ck_ofl(char *s1)
{
	char *possib1;
	char *possib2;
	char *possib3;
	char *possib4;
	char *possib5;

	possib1 = "oo";
	possib2 = "/\\";
	possib3 = "AA";
	possib4 = "AC";
	possib5 = "AC";
	if (ft_strcmp(s1, possib1) == 0
		|| ft_strcmp(s1, possib2) == 0
		|| ft_strcmp(s1, possib3) == 0
		|| ft_strcmp(s1, possib4) == 0
		|| ft_strcmp(s1, possib5) == 0)
		return (1);
	else
		return (0);
}

int		ft_ck_oll(char *s2)
{
	char *possib1;
	char *possib2;
	char *possib3;
	char *possib4;
	char *possib5;

	possib1 = "oo";
	possib2 = "\\/";
	possib3 = "CC";
	possib4 = "AC";
	possib5 = "CA";
	if (ft_strcmp(s2, possib1) == 0
		|| ft_strcmp(s2, possib2) == 0
		|| ft_strcmp(s2, possib3) == 0
		|| ft_strcmp(s2, possib4) == 0
		|| ft_strcmp(s2, possib5) == 0)
		return (1);
	else
		return (0);
}

int		ft_check_char(char *str, char *s1, char *s2)
{
	int width;
	int height;

	width = ft_width(str);
	height = ft_height(str);
	if (ft_ck_fl(s1) == 1 && ft_ck_ll(s2) == 1)
		return (1);
	else if (ft_ck_fl(s1) == 1 && height == 1)
		return (2);
	else if (ft_ck_ofl(s1) == 1 && ft_ck_oll(s2) == 1)
		return (3);
	return (0);
}
