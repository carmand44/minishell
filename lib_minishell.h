/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_minishell.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 02:30:06 by carmand           #+#    #+#             */
/*   Updated: 2017/09/30 22:28:14 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_LS_H
# define LIB_LS_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_sh
{
	char **arg;
	char *PATH;
	char *PWD;
	char **sh_env;
}				t_sh;

t_sh *get_line(char *buf, t_sh *sh);

#endif
