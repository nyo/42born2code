/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 09:28:45 by anyo              #+#    #+#             */
/*   Updated: 2016/08/14 16:11:25 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*p1;
	char	*p2;
	int		i;

	i = 0;
	if (*to_find == 0)
		return (0);
	while (*str != 0)
	{
		p1 = str;
		p2 = to_find;
		while (*p1 == *p2 && *p1 != 0 && *p2 != 0)
		{
			p1 += 1;
			p2 += 1;
		}
		if (*p2 == 0)
			return (str);
		str += 1;
	}
	return (0);
}
