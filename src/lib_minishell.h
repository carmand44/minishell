/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_minishell.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 02:30:06 by carmand           #+#    #+#             */
/*   Updated: 2017/10/16 00:50:51 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MINISHELL_H
# define LIB_MINISHELL_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <dirent.h>
# include <unistd.h>

# define IS_SPACE(x) (x == ' ' || x == '\t' || x == '\r' || x  == '\f')

typedef struct	s_sh
{
	char		**arg;
	char 		**PATH;
	char 		*PWD;
	char		*OLDPWD;
	char		*HOME;
	char 		**sh_env;
	char		*BUF;
}				t_sh;

t_sh			*get_line(char *buf, t_sh *sh);
char			**get_path(char *buf);
char			**set_env(t_sh *sh);
char			**unset_env(t_sh *sh);
void			exec(t_sh *sh, char *bin);
t_sh			*search_bin(t_sh *sh);
void			put_env(char **sh_env);
t_sh			*cd(t_sh *sh);
char			*get_pwd(void);
int				search_env(char **env, char *str);
void			free_sh(t_sh *sh);
void			free_tab(char **tab);

#endif
