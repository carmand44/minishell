/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:23:54 by carmand           #+#    #+#             */
/*   Updated: 2017/10/18 04:54:34 by carmand          ###   ########.fr       */
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
	int 	i;
	int 	i2;
	char 	*tmp;
	int		find;

	i = 0;
	i2 = 0;
	find = search_env(sh, "OLDPWD=");
	tmp = ft_strjoin("OLDPWD=", sh->old_PWD);
	if (find == -1)
	{
		sh->sh_env = modify_env(sh, "OLDPWD=", tmp);
		ft_strdel(&tmp);
	}
	else
	{
		ft_strdel(&tmp);
		if (!(tmp = ft_strsub(sh->sh_env[find], 7, ft_strlen(sh->sh_env[find]))))
			return(NULL);
	}
	if (chdir(tmp) == 0)
	{
		if (sh->PWD)
			free(sh->PWD);
		if (!(sh->PWD = ft_strdup(tmp)))
			return (NULL);
		if (!(sh->sh_env = modify_env(sh, "PWD", sh->PWD)))
			return (NULL);
		ft_putendl(sh->PWD);
	}
	return(sh);

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

char	*exec_cd(t_sh *sh)
{
  char *init;
  char *entry;
  int i;

  i = 0;
  if (sh->PWD == NULL)
  	if (!(sh->sh_env = add_pwd_env(sh)))
  		return (NULL);
  if (!(sh = init_pwd(sh)))
	  return (NULL);
  if (!(init = ft_strdup(sh->PWD)))
    return (NULL);
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
      return(init);
    }
  return(sh->PWD);
}
