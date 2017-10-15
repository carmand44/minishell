/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 23:39:08 by carmand           #+#    #+#             */
/*   Updated: 2017/10/16 01:20:27 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

t_sh	*init_sh(t_sh *sh, char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	free_tab(sh->PATH);
	ft_putchar('O');
	ft_strdel(&sh->PWD);
	ft_strdel(&sh->OLDPWD);
	ft_strdel(&sh->HOME);
	while (env[i] != NULL)
	{
		if (0 == ft_strncmp(env[i], "PATH=", 5))
		{
			if (!(path = ft_strsub(env[i], 5, (ft_strlen(env[i]) - 5))))
				return (NULL);
			if (!(sh->PATH = get_path(path)))
				return (NULL);
			ft_strdel(&path);
		}	
		if (0 == ft_strncmp(env[i], "PWD=", 4))
			if (!(sh->PWD = ft_strsub(env[i], 4, (ft_strlen(env[i]) - 4))))
				return (NULL);
		if (0 == ft_strncmp(env[i], "OLDPWD=", 7))
			if (!(sh->OLDPWD = ft_strsub(env[i], 7, (ft_strlen(env[i]) - 7))))
				return (NULL);
		 if (0 == ft_strncmp(env[i], "HOME=", 5))
			if (!(sh->HOME = ft_strsub(env[i], 5, (ft_strlen(env[i]) - 5))))
				return (NULL);
		i++;
	}
	sh->sh_env = env;
	if (!(sh->BUF = ft_strnew(BUFF_SIZE)))
		return (NULL);
	ft_putendl("OK");
	return (sh);
}

t_sh	*init(t_sh *sh, char **env)
{
	if (!(sh = (t_sh*)malloc(sizeof(t_sh))))
		return (NULL);
	sh->arg = NULL;
	sh->PATH = NULL;
	if (!(sh = init_sh(sh, env)))
		return (NULL);
	return (sh);
}

int		main(int a, char **v, char **env)
{
	size_t ret;
	t_sh *sh;

	sh = NULL;
	if (!(sh = init(sh, env)))
		return (0);
	while(42)
	{
		ft_putstr("$> ");
		sh->arg = NULL;
		if ((ret = read(0, sh->BUF, BUFF_SIZE)))
		{
			sh->BUF[ret] = '\0';
			if (!(sh = get_line(sh->BUF, sh)))
				return (0);
			sh = search_bin(sh);
		}
	}
	a++;
	v[0][0] = 1;
	return (1);
}
