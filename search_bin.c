/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:23:54 by carmand           #+#    #+#             */
/*   Updated: 2017/10/04 02:18:16 by carmand          ###   ########.fr       */
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
		exit (0);
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
	return (1);
}

t_sh	*search_bin(t_sh *sh)
{
	int				i;

	if ((search_builtin(sh) == 0))
		return (sh);
	i = 0;
	while (sh->PATH[i] != NULL)
	{
		if (check_dir(sh->PATH[i], sh))
			break ;
		i++;
	}
	if (sh->PATH[i] != NULL)
		exec(sh, ft_strjoin(sh->PATH[i], ft_strjoin("/", sh->arg[0])));
	else
	{
		//if (check_dir(sh->PWD, sh))
			exec(sh, sh->arg[0]);
			return (sh);
	}
	return (sh);
}
