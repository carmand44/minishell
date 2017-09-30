/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 23:39:08 by carmand           #+#    #+#             */
/*   Updated: 2017/09/30 22:28:19 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

t_sh	*init_sh(t_sh *sh, char **env)
{
	int i;

	i = 0;
	if (!(sh = (t_sh*)malloc(sizeof(t_sh))))
		return (NULL);
	while (env[i] != NULL)
	{
		if (0 == ft_strncmp(env[i], "PATH=", 5))
			if (!(sh->PATH = ft_strsub(env[i], 5, (ft_strlen(env[i]) - 5))))
				return (NULL);
		if (0 == ft_strncmp(env[i], "PWD=", 4))
			if (!(sh->PWD = ft_strsub(env[i], 4, (ft_strlen(env[i]) - 4))))
				return (NULL);
		i++;
	}
	sh->sh_env = env;
	return (sh);
}



int		main(int a, char **v, char **env)
{
	size_t ret;
	char *buf;
	t_sh *sh;
//	pid_t father;

	sh = NULL;
	if (!(sh = init_sh(sh, env)))
		return (0);
	buf = ft_strnew(128);
	while(42)
	{
		ft_putstr("$> ");
		sh->arg = NULL;
		if ((ret = read(0, buf, 128)))
		{
			buf[ret] = '\0';
			if (!(sh = get_line(buf, sh)))
				return (0);
			/*
			father = fork();
			if (father > 0)
				wait(0);
			if (father == 0)
				execve(ft_strjoin(bin, sh->arg[0]), sh->arg, NULL);*/
		}
	}
	a++;
	v[0][0] = 1;
	return (1);
}
