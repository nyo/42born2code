/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:38:31 by anyo              #+#    #+#             */
/*   Updated: 2017/06/19 20:58:58 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
**	INCLUDES
*/

# include "../libft/libft.h"
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

/*
**	DEFINES - MACROS
*/

# define MALLOCSIZE		9999999
# define SIX_MONTHS		15552000
# define ISHIDDEN(x)	x == '.' ? 1 : 0
# define ISDIR(x)		x == 'd' ? 1 : 0
# define ISL(x)			x == 'l' ? 1 : 0
# define ISBR(x)		x == 'R' ? 1 : 0
# define ISA(x)			x == 'a' ? 1 : 0
# define ISR(x)			x == 'r' ? 1 : 0
# define IST(x)			x == 't' ? 1 : 0
# define ISVLDLTR(x)	ISL(x) || ISBR(x) || ISA(x) || ISR(x) || IST(x) ? 1 : 0

/*
**	STRUCTURES
*/

typedef struct	s_options
{
	unsigned int	opt_br : 1;
	unsigned int	opt_l : 1;
	unsigned int	opt_a : 1;
	unsigned int	opt_r : 1;
	unsigned int	opt_t : 1;
	int				max_pw;
	int				max_gr;
	int				max_nl;
	int				max_sz;
	blksize_t		blksize;
}				t_opt;

typedef struct	s_arguments
{
	char				*error;
	char				*modes;
	char				*name;
	struct s_arguments	*next;
}				t_arg;

typedef struct	s_return
{
	char			*ffod_dirname;
	char			*pw_name;
	char			*gr_name;
	char			*error;
	char			*modes;
	char			*lname;
	char			*name;
	char			*size;
	time_t			date;
	nlink_t			nlink;
	blksize_t		blksize;
	struct s_return	*next;
}				t_ret;

typedef struct	s_tdata
{
	char	year[5];
	char	month[4];
	char	day[3];
	char	hour[6];
}				t_tdata;

/*
**	PROTOTYPES
*/

int				arg_len(t_arg *arg);
int				arg_fill(char **rlist, t_arg **arg, t_opt opt);

int				opt_is(char *opt);
int				opt_fill(int argc, char **argv, t_opt *opt);

int				ret_fill(t_arg *arg, t_opt opt);
int				ret_fill_notdir(t_ret **ret, char *filename);
int				ret_fill_ls_1(t_ret **ret, char *dirname, t_opt opt);
int				ret_fill_ls_br(t_ret **ret, t_opt opt, char *dirname);

int				ret_lst_ls_br(char **filelist, char *dirname, t_opt opt);
int				ret_lst_ls_1(char **filelist, char *dirname, t_opt opt);

void			ret_reverse_lst(t_ret **ret);
void			ret_pl_values(t_opt *opt, t_ret *ret);
void			ret_print_node(t_ret *ret, t_arg *arg, t_opt opt, int arg_len);

char			**al_clean(int argc, char **argv);
char			**al_push(int argc, char **argv, t_opt opt);

void			arr_sort_time(char **arr, char *dir, t_opt opt);
void			arr_sort_time_i(char **arr, char *dir, t_opt opt, int x);
char			*format_mode(mode_t mode);
char			*format_date(time_t date);
char			*format_size(mode_t mode, dev_t id, size_t size);
char			*format_lname(char *filename, char *path, off_t size);
int				ls_basic(char *name);
int				malloc_size(char *name);
int				gdate(char *file, char *dir, t_opt opt);

#endif
