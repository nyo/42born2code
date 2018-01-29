/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 18:04:34 by anyo              #+#    #+#             */
/*   Updated: 2016/08/21 20:36:36 by bin0me           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "protocolle.h"

#define BUF_SIZE 4096
#define W ft_width(str)
#define H ft_height(str)

int		main(void)
{
	int		i;
	char	*str;
	char	buf[1];

	i = 0;
	str = (char *)malloc(sizeof(char) * BUF_SIZE + 1);
	while (read(0, buf, sizeof(buf)) > 0)
	{
		str[i] = buf[0];
		i += 1;
	}
	str[i] = '\0';
	if (ft_is_colle(str, ft_keep_s(str), ft_keep_e(str)) == 1)
	{
		ft_print_sbracket(str, W, H);
		ft_putchar('\n');
	}
	else
		ft_putstr("aucune\n");
	free(str);
	return (0);
}
