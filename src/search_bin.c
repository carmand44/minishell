/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:23:54 by carmand           #+#    #+#             */
/*   Updated: 2017/10/20 05:08:05 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

int		check_dir(char *path, t_sh *sh)
{
	DIR             *rep;
	struct dirent   *ent;

	if (!(rep = opendir(path)))
	{
		closedir(rep);
		return (0);
	}
	while ((ent = readdir(rep)))
	{
		if ((ft_strcmp(sh->arg[0], ent->d_name)) == 0)
		{
			closedir(rep);
			return (1);
		}
	}
	closedir(rep);
	free(ent);
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
		put_env(sh->sh_env, sh->s_env);
		return (0);
	}
	else if ((ft_strcmp(sh->arg[0], "cd")) == 0)
	{
		if (!(sh->PWD = exec_cd(sh)))
			return (-1);
		return (0);
	}
	else if ((ft_strcmp(sh->arg[0], "clear")) == 0)
	{
		ft_putstr("\033[H\033[2J");
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
	char			*tmp;
	char			*tmp2;
	//struct stat		*sts;

	//sts = NULL;
	if ((search_builtin(sh) == 0))
		return (sh);
	i = 0;
	if (sh->PATH)
	{
		while (i < sh->s_PATH)
		{
			if (check_dir(sh->PATH[i], sh))
				break ;
			i++;
		}
		if (sh->PATH[i] != NULL)
		{
			tmp = ft_strjoin("/", sh->arg[0]);
			tmp2 = ft_strjoin(sh->PATH[i], tmp);
			ft_strdel(&tmp);
			exec(sh, tmp2);
			ft_strdel(&tmp2);
			return (sh);
		}
		if (access(sh->arg[0], F_OK) == 0)
		{
			exec(sh, sh->arg[0]);
			return (sh);
		}
		else 
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(sh->arg[0], 2);
			ft_putendl_fd(" command not found", 2);
		}
	}
	return (sh);
}
