/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 23:39:08 by carmand           #+#    #+#             */
/*   Updated: 2017/10/20 00:45:18 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

t_sh *init_sh_first(t_sh *sh, char **env)
{
	int i;
	char *path;

	i = 0;
	path = NULL;
	sh->PWD = NULL;
	sh->PATH = NULL;
	sh->old_PWD = NULL;
	sh->sh_env = NULL;
	while (env[i] != NULL)
	{
		if (0 == ft_strncmp(env[i], "PATH=", 5))
		{
			if (!(path = ft_strsub(env[i], 5, (ft_strlen(env[i]) - 5))))
				return (NULL);
			if (!(sh->PATH = get_path(path, sh)))
				return (NULL);
			free(path);
		}
		if (0 == ft_strncmp(env[i], "PWD=", 4))
		{
			if (!(sh->PWD = ft_strsub(env[i], 4, (ft_strlen(env[i]) - 4))))
				return (NULL);
		}
		i++;
	}

	if (!(sh->sh_env = (char**)malloc(sizeof(char*) * i)))
		return (NULL);
	sh->s_env = i;
	i = 0;
	while (i < sh->s_env)
	{
		if (!(sh->sh_env[i] = ft_strdup(env[i])))
			return (NULL);
		i++;
	}
	//sh->sh_env = modify_env(sh, "OLDPWD", sh->PWD);
	return (sh);
}

t_sh *init_sh(t_sh *sh, char **env)
{
	int i;
	char *path;
	char	*tmp;

	i = 0;
	path = NULL;
	ft_strdel(&sh->PWD);
	free_tab(sh->PATH, sh->s_PATH);
	ft_strdel(&sh->old_PWD);
	while (i < sh->s_env)
	{
		if (0 == ft_strncmp(env[i], "PATH=", 5))
		{
			if (!(path = ft_strsub(env[i], 5, (ft_strlen(env[i]) - 5))))
				return (NULL);
			if (!(sh->PATH = get_path(path, sh)))
				return (NULL);
			free(path);
		}
		if (0 == ft_strncmp(env[i], "PWD=", 4))
		{
			ft_strdel(&sh->PWD);
			if (!(tmp = ft_strsub(env[i], 4, (ft_strlen(env[i]) - 4))))
				return (NULL);
			if (!(sh->PWD = ft_strdup(tmp)))
				return (NULL);
			ft_strdel(&tmp);
		}
		i++;
	}
	sh->sh_env = env;
	return (sh);
}

int		main(int a, char **v, char **env)
{
	size_t ret;
	t_sh *sh;

	sh = NULL;
	if (!(sh = (t_sh*)malloc(sizeof(t_sh))))
		return (0);
	sh->sh_env = NULL;
	if (!(sh = init_sh_first(sh, env)))
		return (0);
	sh->buf = NULL;
	sh->buf = ft_strnew(128);
	sh->arg = NULL;
	while(42)
	{
		if (!(sh = init_sh(sh, sh->sh_env)))
			return (0);
		ft_putstr("\033[32m");
		if (sh->PWD)
			ft_putstr(sh->PWD);
		ft_putstr("$> ");
		ft_putstr("\033[00m");
		free_tab(sh->arg, sh->s_arg);
		if ((ret = read(0, sh->buf, 128)))
		{
			sh->buf[ret] = '\0';
			if (!(sh = get_line(sh->buf, sh)))
				return (0);
			sh = search_bin(sh);
		}
	}
	a++;
	v[0][0] = 1;
	return (1);
}
