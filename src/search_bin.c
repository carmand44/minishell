/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:23:54 by carmand           #+#    #+#             */
/*   Updated: 2017/10/16 00:45:47 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

int		check_dir(char *path, t_sh *sh)
{
	DIR             *rep;
	struct dirent   *ent;

	if (!(rep = opendir(path)))
		return (0);
	while ((ent = readdir(rep)))
	{
		if ((ft_strcmp(sh->arg[0], ent->d_name)) == 0)
		{
			closedir(rep);
			return (1);
		}
	}
	return (0);
}

int		search_builtin(t_sh *sh)
{
	if ((ft_strcmp(sh->arg[0], "exit")) == 0)
	{
		free_sh(sh);
		exit (0);
	}
	else if ((ft_strcmp(sh->arg[0], "echo")) == 0)
	{
		ft_putendl(sh->PWD);
		return (0);
	}
	else if ((ft_strcmp(sh->arg[0], "env")) == 0)
	{
		put_env(sh->sh_env);
		return (0);
	}
	else if ((ft_strcmp(sh->arg[0], "cd")) == 0)
	{
		if (!(sh = cd(sh)))
			return (-1);
		return (0);
	}
	else if ((ft_strcmp(sh->arg[0], "setenv")) == 0)
	{
		if (!(sh->sh_env = set_env(sh)))
			return (-1);
		return (0);
	}
	else if ((ft_strcmp(sh->arg[0], "unsetenv")) == 0)
	{
		if (!(sh->sh_env = unset_env(sh)))
			return (-1);
		return (0);
	}
	return (1);
}

t_sh	*search_bin(t_sh *sh)
{
	int				i;

	if ((search_builtin(sh) == 0))
		return (sh);
	i = 0;
	if (sh->PATH)
	{
		while (sh->PATH[i] != NULL)
		{
			if (check_dir(sh->PATH[i], sh))
				break ;
			i++;
		}
		if (sh->PATH[i] != NULL)
			exec(sh, ft_strjoin(sh->PATH[i], ft_strjoin("/", sh->arg[0])));
	}
	else
	{
		//if (check_dir(sh->PWD, sh))
			exec(sh, sh->arg[0]);
			return (sh);
	}
	return (sh);
}
