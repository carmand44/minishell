/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:23:54 by carmand           #+#    #+#             */
/*   Updated: 2017/10/05 22:48:44 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

char	*cut_one(char *entry, char *tmp)
{
	int i;

	i = ft_strlen(entry);
	while(i > 0)
	{
		if (entry[i] == '/')
			break;
		i--;
	}
	if (!(tmp = ft_strsub(entry, 0, i)))
		return (NULL);
	free(entry);
	return(tmp);
}

t_sh	*go_home(t_sh *sh)
{
	int i;

	i = 0;
	while(sh->sh_env[i])
	{
		if(ft_strncmp("HOME=", sh->sh_env[i], 5) == 0)
		{
			if ((sh->PWD = ft_strsub(sh->sh_env[i], 5, (ft_strlen(sh->sh_env[i]) - 5))))
					return (sh);
			else
				return(NULL);
		}
		i++;
	}
	return(sh);
}

char	**update_env(t_sh *sh)
{
	int i;

	i = 0;
	while(sh->sh_env[i])
	{
		if (ft_strncmp("PWD=", sh->sh_env[i], 4) == 0)
		{
			if (!(sh->sh_env[i] = ft_strdup(ft_strjoin("PWD=", sh->PWD))))
				return (NULL);
			return(sh->sh_env);
		}
		i++;
	}
	return(sh->sh_env);
}

char 	*add_pwd(t_sh *sh)
{
	int 	i;
	int 	dot;
	char	*tmp;

	i = 0;
	dot = 0;
	tmp = NULL;
	if (sh->arg[1] == NULL)
	{
		if (!(sh = go_home(sh)))
			return (NULL);
	}
	else if (sh->arg[1][0] == '.')
	{
		while(sh->arg[1][dot] == '.')
		{
			if (dot > 0)
			{
				if (!(sh->PWD = cut_one(sh->PWD, tmp)))
					return (NULL);
				free(tmp);
			}
			dot++;
		}

	}
	else
		if (!(sh->PWD = ft_strdup(((ft_strjoin(ft_strjoin(sh->PWD, "/"), sh->arg[1]))))))
			return (NULL);
	if (!(sh->sh_env = update_env(sh)))
		return (NULL);
	return(sh->PWD);
}

char	*exec_cd(t_sh *sh)
{
	int 	i;
	int 	i2;
	char	*init;
	char	*entry;

	i = 1;
	i2 = 0;
	if(!(init = ft_strdup(sh->PWD)))
			return (NULL);
	if (!(entry = add_pwd(sh)))
		return (init);
	if (chdir(entry) == 0)
		return(entry);
	else
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl(sh->arg[1]);
		return(init);
	}
	return(sh->PWD);
}
