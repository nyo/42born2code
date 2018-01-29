/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 02:34:39 by anyo              #+#    #+#             */
/*   Updated: 2016/08/13 13:06:17 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i += 1;
	while (src[j])
	{
		dest[i + j] = src[j];
		j += 1;
	}
	dest[i + j] = '\0';
	return (dest);
}
