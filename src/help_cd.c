/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:23:54 by carmand           #+#    #+#             */
/*   Updated: 2017/10/19 02:24:26 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

int	count_back(char	*name)
{
	int i;
	int back;

	i = 0;
	back = 0;
	while(name[i])
		ft_putchar(name[i++]);
	return(back);
}

char *cd_dot(t_sh *sh, char *tmp)
{
	int back;

	back = count_back(sh->arg[1]);

	tmp = NULL;
	while(back > 0)
	{
		if (!(sh->PWD = cut_one(sh->PWD, tmp, sh)))
			return (NULL);
		free(tmp);
		back--;
	}
	return (sh->PWD);
}

int no_arg(char *arg, t_sh *sh)
{
	int i;

	i = 0;
	while(i < sh->s_arg)
		if (arg[i++] != ' ')
			return(1);
	return(0);
}

char *add_pwd(t_sh *sh)
{
	char*tmp;

	tmp = NULL;
	if (sh->s_arg == 1 || sh->arg[1][0] == '#' || sh->arg[1][0] == '~' || sh->arg[1][0] == ';')
	{
		if (!(sh = go_home(sh)))
			return (NULL);
	}
	else if (sh->arg[1][0] == '.')
		sh->PWD = cd_dot(sh, tmp);
	else if (sh->arg[1][0] == '/')
	{
		free(sh->PWD);
		if (!(sh->PWD = ft_strdup(sh->arg[1])))
			return (NULL);
	}
	else if (sh->arg[1][0] == '-')
	{
		ft_putendl("GO OLG PWD");
		sh = go_old_pwd(sh);
		ft_putendl("FINISH");
		return(sh->PWD);
	}
	else
	{
//		ft_strdel
		if (!(sh->PWD = ft_strdup(((ft_strjoin(ft_strjoin(sh->PWD, "/"), sh->arg[1]))))))
			return (NULL);
	}
	return(sh->PWD);
}

char **add_pwd_env(t_sh *sh)
{
	char	*tmp;
	char buf[126];
/*	int i;
	char **tmp;


	i = 0;
	if (!(tmp = (char**)malloc(sizeof(char*) * (sh->sh_env + 1))))
		return (NULL);
	i = 0;
	while(i < )
	{
		tmp[i] = ft_strdup(sh->sh_env[i]);
		i++;
	}
	tmp[i] = ft_strdup;
	tmp[i + 1] = NULL;
	free_tab(sh->sh_env, sh->s_env);
	return(tmp);*/
	if(!(tmp = 	ft_strjoin("PWD=", getcwd(buf, 126))))
	  return (NULL);
	sh->sh_env = modify_env(sh, "PWD", tmp);
	ft_strdel(&tmp);
	return(sh->sh_env);

}

t_sh *init_pwd(t_sh *sh)
{
	int i;
	char	*tmp;

	i = 0;
	while (i < sh->s_env)
	{
		if (0 == ft_strncmp(sh->sh_env[i], "PWD=", 4))
		{
			if (!(tmp = ft_strsub(sh->sh_env[i], 4, (ft_strlen(sh->sh_env[i]) - 4))))
				return (NULL);
			ft_strdel(&sh->PWD);
			if (!(sh->PWD = ft_strdup(tmp)))
				return (NULL);
			ft_strdel(&tmp);
		}
		i++;
	}
	return(sh);
}
