/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:23:54 by carmand           #+#    #+#             */
/*   Updated: 2017/10/11 03:14:01 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

char *cd_dot(t_sh *sh, char *tmp)
{
	int dot;

	dot = 0;
	while(sh->arg[1][dot] == '.')
	{
		if (dot > 0)
		{
			if (!(sh->PWD = cut_one(sh->PWD, tmp, sh)))
				return (NULL);
			free(tmp);
		}
		dot++;
	}
	return (sh->PWD);
}

int no_arg(char *arg)
{
	int i;

	i = 0;
	while(arg[i])
		if (arg[i++] != ' ')
			return(1);
	return(0);
}

char *add_pwd(t_sh *sh)
{
	char*tmp;

	tmp = NULL;

	if (((sh->arg[1] == NULL) || (no_arg(sh->arg[1]) == 0)))
	{
		if (!(sh = go_home(sh)))
			return (NULL);
	}
	else if (sh->arg[1][0] == '.')
		sh->PWD = cd_dot(sh, tmp);
	else if (sh->arg[1][0] == '/')
	{
		free(sh->PWD);
		if (!(sh->PWD = sh->arg[1]))
			return (NULL);
	}
	else if (sh->arg[1][0] == '-')
	{
		ft_putendl("GO OLG PWD");
		sh = go_old_pwd(sh);
		put_env(sh->sh_env);
		ft_putendl("FINISH");
		return(sh->PWD);
	}
	else
	{
		if (!(sh->PWD = ft_strdup(((ft_strjoin(ft_strjoin(sh->PWD, "/"), sh->arg[1]))))))
			return (NULL);
	}
	return(sh->PWD);
}

char **add_pwd_env(t_sh *sh)
{
	int i;
	char **tmp;
	char buf[126];

	i = 0;
	while(sh->sh_env[i])
		i++;
	if (!(tmp = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = 0;
	while(sh->sh_env[i])
	{
		tmp[i] = ft_strdup(sh->sh_env[i]);
		i++;
	}
	tmp[i] = ft_strdup(ft_strjoin("PWD=", getcwd(buf, 126)));
	tmp[i + 1] = NULL;
	ft_free_char_2d(sh->sh_env);
	return(tmp);
}

t_sh *init_pwd(t_sh *sh)
{
	int i;

	i = 0;
	while (sh->sh_env[i] != NULL)
	{
		if (0 == ft_strncmp(sh->sh_env[i], "PWD=", 4))
		{
			if (!(sh->PWD = ft_strsub(sh->sh_env[i], 4, (ft_strlen(sh->sh_env[i]) - 4))))
				return (NULL);
		}
		i++;
	}
	return(sh);
}
