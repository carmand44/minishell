/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:32:15 by carmand           #+#    #+#             */
/*   Updated: 2017/10/20 04:57:00 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	put_env(char **sh_env, int s_env)
{
	int	i;

	i = 0;
	while (i < s_env)
	{
		ft_putendl(sh_env[i]);
		i++;
	}
}

int		search_env(t_sh *sh, char *line)
{
	int i;

	i = 0;
	while(i < sh->s_env)
	{
		if (ft_strncmp(sh->sh_env[i], line, ft_strlen(line)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_strlen_2d(t_sh *sh)
{
	int i;

	i = 0;
	while(i < sh->s_env)
		i++;
	return(i);
}

char	**realloc_env(t_sh *sh, char *place)
{
	char	**new;
	char	*tmp;
	int 	start;

	start = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (sh->s_env + 2))))
		return (NULL);
	while(start < sh->s_env)
	{
		new[start] = ft_strdup(sh->sh_env[start]);
		start++;
	}
	if(sh->s_arg > 1)
	{
		if (sh->arg[1][0] == '-')
		{
			if(!(tmp = ft_strjoin("OLDPWD=", sh->old_PWD)))
				return (NULL);
			ft_putendl(sh->old_PWD);
			new[start] = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		else
			new[start] = ft_strdup(place);
	}
	new[start + 1] = NULL;
	sh->s_env = start;
	if (start > 0)
		free_tab(sh->sh_env, sh->s_env);
	return (new);
}

char	 **modify_env(t_sh *sh, char *line, char *modify)
{
	int 	i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	if (!(tmp2 = ft_strjoin(line, "=")))
		return (NULL);
	if (!(tmp = ft_strjoin(tmp2, modify)))
		return (NULL);
	ft_strdel(&tmp2);
	if ((i = search_env(sh, line)) != -1)
	{
		ft_strdel(&sh->sh_env[i]);
		sh->sh_env[i] = ft_strdup(tmp);
	}
	else
		if(!(sh->sh_env = realloc_env(sh, modify)))
			return (NULL);
	ft_strdel(&tmp);
	return (sh->sh_env);
}

char	**add_env(t_sh *sh , int i)
{
	int		s;
	char	*tmp;
	char	**new;

	s = 0;
	tmp = NULL;
	new = NULL;
	if (i == -1)
	{
		if (!(new = (char**)malloc(sizeof(char*) * (sh->s_env + 1))))
		   return (NULL);
		while (s < sh->s_env)
		{
			if (!(new[s] = ft_strdup(sh->sh_env[s])))
				return (NULL);
			s++;
		}
		if (sh->s_arg == 3)
		{
			if (!(tmp = ft_strjoin(sh->arg[1], "=")))
				return (NULL);
			if (!(new[s] = ft_strjoin(tmp, sh->arg[2])))
					return (NULL);
				ft_strdel(&tmp);
		}
		else
			if (!(new[s] = ft_strjoin(sh->arg[1], "=")))
				return (NULL);
		free_tab(sh->sh_env, sh->s_env);
		sh->s_env += 1;
		return (new);
	}
	else
	{
		ft_strdel(&sh->sh_env[i]);
		if (sh->s_arg == 3)
		{
			if (!(tmp = ft_strjoin(sh->arg[1], "=")))
				return (NULL);
			if (!(sh->sh_env[i] = ft_strjoin(tmp, sh->arg[2])))
				return (NULL);
			ft_strdel(&tmp);
		}
		else
			if (!(new[s] = ft_strjoin(sh->arg[1], "=")))
				return (NULL);
	}
	return (sh->sh_env);
}

char	**set_env(t_sh *sh)
{
	int		i;
	char	*tmp;

	i = -2;
	tmp = NULL;
	if (!((sh->s_arg == 2) || (sh->s_arg == 3)))
		return (sh->sh_env);
	tmp = ft_strjoin(sh->arg[1], "=");
	i = search_env(sh, tmp);
	ft_strdel(&tmp);
	return (add_env(sh, i));
}



char	**unset_env(t_sh *sh)
{
	int 	j;
	int		k;
	char	**new;

	j = -1;
	new = NULL;
	k = 0;
	if (!((sh->s_arg == 2) || (sh->s_arg == 3)))
		return (sh->sh_env);
	j = search_env(sh, sh->arg[1]);
	if (j == -1)
		return (sh->sh_env);
	else
	{
		if (!(new = (char**)malloc(sizeof(char*) * (sh->s_env - 1))))
			return (NULL);
		while (k < j)
		{
			if (!(new[k] = ft_strdup(sh->sh_env[k])))
				return (NULL);
			k++;
		}
		while (k != (sh->s_env - 1))
		{
			if (!(new[k] = ft_strdup(sh->sh_env[k + 1])))
				  return (NULL);
			k++;
		}
	}
	sh->s_env--;
	free_tab(sh->sh_env, sh->s_env + 1);
	return (new);
}
