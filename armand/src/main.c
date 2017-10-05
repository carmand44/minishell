/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 23:39:08 by carmand           #+#    #+#             */
/*   Updated: 2017/10/05 01:50:31 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

t_sh	*init_sh(t_sh *sh, char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	if (!(sh = (t_sh*)malloc(sizeof(t_sh))))
		return (NULL);
	while (env[i] != NULL)
	{
		if (0 == ft_strncmp(env[i], "PATH=", 5))
		{
			if (!(path = ft_strsub(env[i], 5, (ft_strlen(env[i]) - 5))))
				return (NULL);
			if (!(sh->PATH = get_path(path)))
				return (NULL);
			free(path);
		}	
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

	sh = NULL;
	if (!(sh = init_sh(sh, env)))
		return (0);
	buf = ft_strnew(128);
	while(42)
	{
		ft_putstr("\033[32m");
		ft_putstr(ft_strjoin(sh->PWD,"$> "));
		ft_putstr("\033[00m");
		sh->arg = NULL;
		if ((ret = read(0, buf, 128)))
		{
			buf[ret] = '\0';
			if (!(sh = get_line(buf, sh)))
				return (0);
			sh = search_bin(sh);
		}
	}
	a++;
	v[0][0] = 1;
	return (1);
}
