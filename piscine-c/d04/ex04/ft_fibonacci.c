/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 18:26:06 by anyo              #+#    #+#             */
/*   Updated: 2016/08/13 12:03:54 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	else if (index <= 1)
	{
		return (index);
	}
	else
	{
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	}
}
