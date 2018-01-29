/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 18:59:34 by anyo              #+#    #+#             */
/*   Updated: 2016/08/23 20:31:29 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

#define BUF_SIZE	29463

void	p_error(char *str)
{
	ft_putstr("cat: ");
	ft_putstr(str);
	ft_putstr(": No such file or directory\n");
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		fd;
	char	str[BUF_SIZE + 1];
	char	buf[1];

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		fd = open(argv[i + 1], O_RDONLY);
		if (fd == -1)
			p_error(argv[i + 1]);
		while (read(fd, buf, sizeof(buf)) > 0)
		{
			str[j] = buf[0];
			j += 1;
		}
		str[j] = '\0';
		ft_putstr(str);
		i += 1;
	}
	return (0);
}
