/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 18:28:13 by anyo              #+#    #+#             */
/*   Updated: 2016/08/23 18:31:21 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "df.h"

#define BUF_SIZE	29463

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	str[BUF_SIZE];
	char	buf[1];

	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (0);
		while (read(fd, buf, sizeof(buf)) > 0)
		{
			str[i] = buf[0];
			i += 1;
		}
		str[i] = '\0';
		ft_putstr(str);
	}
	else
		write(2, "Too many arguments.\n", 20);
	return (0);
}
