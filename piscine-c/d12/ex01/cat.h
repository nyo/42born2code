/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 18:57:28 by anyo              #+#    #+#             */
/*   Updated: 2016/08/23 18:58:11 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>

void	ft_putstr(char *str);
void	p_error(char *str);

#endif
