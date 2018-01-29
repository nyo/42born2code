/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:24:14 by anyo              #+#    #+#             */
/*   Updated: 2017/08/26 14:20:58 by anyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
**	INCLUDES
*/

# include "./get_next_line.h"
# include "../libft/libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/uio.h>

/*
**	MACROS
*/

# define BLANKCHAR1(x)	(x == ' ' || x == '\t' || x == '\n') ? 1 : 0
# define BLANKCHAR2(x)	(x == '\r' || x == '\f' || x == '\v') ? 1 : 0
# define ISBLANK(x)		(BLANKCHAR1(x) == 1 || BLANKCHAR2(x) == 1) ? 1 : 0

# define CL_MAGENTA	"\033[0;35m"
# define CL_YELLOW	"\033[0;33m"
# define CL_RESET	"\033[0m"
# define CL_WHITE	"\033[1;37m"
# define CL_GREY	"\033[0;37m"
# define CL_BLUE	"\033[0;36m"

/*
**	STRUCTURES
*/

typedef struct	s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}				t_env;

/*
**	FUNCTIONS
*/

char			*get_cmd_path(t_env **env, char **command);
char			*get_env_val(t_env **env, char *name);

char			**cmd_format(t_env **env, char *raw_cmd);
void			cmd_execute(t_env **env, char **command);

void			replace_tild(t_env **env, char **command);
void			replace_dotdot(char **command);
void			replace_dot(char **command);

char			**env_to_environ(t_env **env, char **command);
char			**env_to_arr(t_env **env);
void			env_replace(t_env **env, char *name, char *value);
void			env_append(t_env **env, char *name, char *value);
void			env_init(t_env **env, char **environ);
void			env_free(t_env **env);
void			env_print(t_env *env);

void			my_togglecolor(t_env **env);
void			my_unsetenv(t_env **env, char **command);
void			my_setenv(t_env **env, char **command);
void			my_echo(t_env **env, char **command);
void			my_exit(t_env **env, char **command);
void			my_env(t_env **env, char **command);
void			my_cd(t_env **env, char **command);

void			sig_init(int sig);
void			sig_exe(int sig);

char			*try_cmd_path(char *path, char *cmd);
void			exe_cute(char **environ, char **command, char *full_path);
void			display_prompt(void);
int				is_line_blank(char *line);

#endif
