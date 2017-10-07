/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_minishell.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 02:30:06 by carmand           #+#    #+#             */
/*   Updated: 2017/10/07 00:35:23 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MINISHELL_H
# define LIB_MINISHELL_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <dirent.h>
# include <unistd.h>

# define IS_SPACE(x) (x == ' ' || x == '\t' || x == '\r' || x  == '\f')

typedef struct s_sh
{
	char **arg;
	char **PATH;
	char *PWD;
	char **sh_env;
}				t_sh;

t_sh	*get_line(char *buf, t_sh *sh);
char    **get_path(char *buf);
char    **set_env(t_sh *sh);
char	**unset_env(t_sh *sh);
void    exec(t_sh *sh, char *bin);
t_sh    *search_bin(t_sh *sh);
void    put_env(char **sh_env);
char 	*exec_cd(t_sh *sh);
#endif
