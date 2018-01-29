/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bin0me                                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:42:25 by bin0me            #+#    #+#             */
/*   Updated: 2016/12/04 17:47:34 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** file_to_str
**
** Definition:  take a file and store it in a string.
**
** Return value: char* of the string with file
*/

char	*file_to_str(char *filename)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*str;

	str = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	str[BUF_SIZE] = '\0';
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("open() error. Check file.");
		return (NULL);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	if (close(fd) == -1)
	{
		ft_putendl("close() error.");
		return (NULL);
	}
	return (str);
}
