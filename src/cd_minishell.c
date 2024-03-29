/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:23:54 by carmand           #+#    #+#             */
/*   Updated: 2017/10/20 04:57:45 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

char	*cut_one(char *entry, char *tmp, t_sh *sh)
{
	int i;

	i = ft_strlen(entry);
	while(i > 0)
	{
		if (entry[i] == '/')
			break;
		i--;
	}
	if (i == 0)
	{
		free(sh->PWD);
		if (!(sh->PWD = ft_strdup("/")))
			return (NULL);
		return(sh->PWD);
	}
	if (!(tmp = ft_strsub(entry, 0, i)))
		return (NULL);
	free(entry);
	return(tmp);
}

t_sh	*go_old_pwd(t_sh *sh)
{
	char 	*tmp;
	int		find;

	find = search_env(sh, "OLDPWD=");
	if (find == -1)
	{
		if (!(tmp = ft_strjoin("OLDPWD=", sh->old_PWD)))
			return (NULL);;
		sh->sh_env = modify_env(sh, "OLDPWD=", tmp);
	}
	else
	{
		if (!(tmp = ft_strsub(sh->sh_env[find], 7, ft_strlen(sh->sh_env[find]))))
			return(NULL);
	}
	ft_strdel(&sh->PWD);
	sh->PWD = ft_strdup(tmp);
	ft_strdel(&tmp);
	return(sh);
}

t_sh	*go_home(t_sh *sh)
{
	int i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while(i < sh->s_env)
	{
		if(ft_strncmp("HOME=", sh->sh_env[i], 5) == 0)
		{
			if (!(tmp = ft_strsub(sh->sh_env[i], 5, (ft_strlen(sh->sh_env[i]) - 5))))
				return (NULL);
			if (sh->PWD != NULL)
				ft_strdel(&sh->PWD);
			sh->PWD = ft_strdup(tmp);
			ft_strdel(&tmp);
			return (sh);
		}
		i++;
	}
	return(sh);
}

int	check_error(t_sh *sh)
{
	if (sh->s_arg == 3)
	{
		ft_putstr_fd("cd: string in pwd: ", 2);
		ft_putendl_fd(sh->arg[1], 2);
		return (0);
	}
	else if (sh->s_arg > 3)
	{
		ft_putendl_fd("cd: too many arguments", 2);
		return (0);
	}
	return (1);
}

char	*exec_cd(t_sh *sh)
{
  char *init;
  char *entry;

  init = NULL;
  if (!(check_error(sh)))
	  return(sh->PWD);
  if (sh->PWD == NULL)
  	if (!(sh->sh_env = add_pwd_env(sh)))
  		return (NULL);
  if (!(sh = init_pwd(sh)))
	  return (NULL);
  if (!(init = ft_strdup(sh->PWD)))
    return (NULL);
  if (sh->old_PWD)
	  ft_strdel(&sh->old_PWD);
  sh->old_PWD = init;
  if (!(entry = add_pwd(sh)))
	  return (init);
  if (chdir(entry) == 0)
  {
	  sh->sh_env = modify_env(sh, "PWD", sh->PWD);
	  sh->sh_env = modify_env(sh, "OLDPWD", init);
	  return(entry);
  }
  else
  {
      ft_putstr_fd("cd: no such file or directory: ", 2);
      ft_putendl_fd(sh->arg[1], 2);
//	  ft_strdel(&entry);
	  //  ft_strdel(&init);
  }
  return(sh->PWD);
}
