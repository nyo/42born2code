/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 11:19:38 by anyo              #+#    #+#             */
/*   Updated: 2016/08/18 14:33:28 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef	int		t_bool;
# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define EVEN(x) ((x % 2) == 0 ? (1) : (0))
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

#endif
