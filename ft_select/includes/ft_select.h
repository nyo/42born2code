/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:38:41 by anyo              #+#    #+#             */
/*   Updated: 2017/09/28 16:31:49 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

/*
**	-------------------------------------------------------------------------- +
**	INCLUDES
**	-------------------------------------------------------------------------- +
*/

# include "../libft/libft.h"
# include <sys/ioctl.h>
# include <termios.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <term.h>

/*
**	-------------------------------------------------------------------------- +
**	DEFINES: COMMON
**	-------------------------------------------------------------------------- +
*/

# define FALSE				0
# define TRUE				1
# define RESET				2

/*
**	-------------------------------------------------------------------------- +
**	DEFINES: COLORS
**	-------------------------------------------------------------------------- +
*/

# define C_RESET			"\033[0m"
# define C_BOLD_ON			"\033[1m"
# define C_ITALIC_ON		"\033[3m"
# define C_UNDERLINE_ON		"\033[4m"
# define C_INVERSE_ON		"\033[7m"
# define C_BOLD_OFF			"\033[22m"
# define C_ITALIC_OFF		"\033[23m"
# define C_UNDERLINE_OFF	"\033[24m"
# define C_INVERSE_OFF		"\033[27m"

# define FG_BLACK			"\033[30m"
# define FG_RED				"\033[31m"
# define FG_GREEN			"\033[32m"
# define FG_YELLOW			"\033[33m"
# define FG_BLUE			"\033[34m"
# define FG_MAGENTA			"\033[35m"
# define FG_CYAN			"\033[36m"
# define FG_WHITE			"\033[37m"
# define FG_RESET			"\033[39m"

# define BG_BLUE			"\033[44m"
# define BG_WHITE			"\033[47m"
# define BG_RESET			"\033[49m"

/*
**	-------------------------------------------------------------------------- +
**	DEFINES: KEYS
**	-------------------------------------------------------------------------- +
*/

# define KEY_UP				"\033[Am"
# define KEY_DOWN			"\033[Bm"
# define KEY_RIGHT			"\033[Cm"
# define KEY_LEFT			"\033[Dm"
# define KEY_DELETE			"\033[3~"
# define KEY_BACKSPACE		127
# define KEY_COLOR			126
# define KEY_RESIZE			-69
# define KEY_S_NONE			45
# define KEY_S_ALL			42
# define KEY_HIDE			36
# define KEY_SPACE			32
# define KEY_ESCAPE			27
# define KEY_RETURN			10
# define KEY_END			0

/*
**	-------------------------------------------------------------------------- +
**	LINKED LISTS
**	-------------------------------------------------------------------------- +
*/

typedef struct		s_files
{
	char			*file_name;
	int				file_selected;
	int				file_current;
	int				file_exists;
	int				file_color;
	struct s_files	*prev;
	struct s_files	*next;
}					t_files;

/*
**	-------------------------------------------------------------------------- +
**	GLOBALS
**	-------------------------------------------------------------------------- +
*/

t_files				*g_files;
char				*g_mem;

/*
**	-------------------------------------------------------------------------- +
**	PROTOTYPES
**	-------------------------------------------------------------------------- +
*/

void				raw_term_mode(void);
void				def_term_mode(void);

int					exec_select(char **files);
int					exec_key(t_files **head, char **ds_mem, char *key);

int					get_lst_width(t_files *head);
int					get_lst_height(t_files *head);
t_files				*get_current_file(t_files **head);

void				clean_exit(t_files **head, char *ds_mem);
void				clean_screen(void);

void				disp_list(struct winsize ws, t_files *head);
void				disp_back(struct winsize ws, t_files *head);
int					disp_check(struct winsize ws, int lst_h, int lst_w);
int					disp_check_help(struct winsize ws, char *help_content);

int					lst_init(t_files **head, char **files);
void				lst_del_tail(t_files **head, t_files *curr);
void				lst_del_middle(t_files *curr);
void				lst_del_head(t_files **head);

void				signal_handler(void);
void				sig_int(int sig);
void				sig_tstp(int sig);
void				sig_cont(int sig);
void				sig_winch(int sig);

int					press_ds(t_files **head, char **ds_mem, char *key);
int					press_unselect_all(t_files **head, char *key);
int					press_select_all(t_files **head, char *key);
int					press_check(t_files **head, char *key);
int					press_color(t_files **head, char *key);
int					press_arrow_down(t_files **head, char *key);
int					press_arrow_up(t_files **head, char *key);
int					press_delete(t_files **head, char *key);
int					press_return(t_files **head, char *key);
int					press_space(t_files **head, char *key);

int					tc_putc(int c);

#endif
