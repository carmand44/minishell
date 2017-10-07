/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:32:15 by carmand           #+#    #+#             */
/*   Updated: 2017/10/07 03:30:22 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	put_env(char **sh_env)
{
	int	i;

	i = 0;
	while (sh_env[i] != NULL)
	{
		ft_putendl(sh_env[i]);
		i++;
	}
}

char	**add_env(t_sh *sh , int i)
{
	int		j;
	int		s;
	char	**new;

	j = 0;
	s = 0;
	if (i == -1)
	{
		new = NULL;
		while (sh->sh_env[j] != NULL)
			j++;
		if (!(new = (char**)malloc(sizeof(char*) * (j + 2))))
		   return (NULL);
		while (s < j)
		{
			if (!(new[s] = ft_strdup(sh->sh_env[s])))
				return (NULL);
			s++;
		}
		if (!(new[s] = ft_strdup(ft_strjoin \
			(ft_strjoin(sh->arg[1], "="), sh->arg[2]))))
			return (NULL);
		new[s + 1] = NULL;
		sh->sh_env = NULL;
		return (new);
	}
	else
	{
		sh->sh_env[i] = NULL;
		if (!(sh->sh_env[i] = ft_strdup(ft_strjoin
			(ft_strjoin(sh->arg[1], "="), sh->arg[2]))))
			return (NULL);
	}
	return (sh->sh_env);
}

char	**set_env(t_sh *sh)
{
	int i;

	i = 0;
	if (sh->arg[1] == NULL)
		return (sh->sh_env);
	while (sh->sh_env[i] != NULL)
	{
		if (ft_strncmp(ft_strjoin(sh->arg[1], "="),
			sh->sh_env[i], (ft_strlen(sh->arg[1]) + 1)) == 0)
			break ;
		i++;
	}
	if (sh->sh_env[i] == NULL)
		return (add_env(sh, -1));
	else
		return (add_env(sh, i));
}

char	**unset_env(t_sh *sh)
{
	int		i;
	int 	j;
	int		k;
	char	**new;

	i = 0;
	j = -1;
	new = NULL;
	k = 0;
	while (sh->sh_env[i] != NULL)
	{
		if (ft_strncmp(ft_strjoin(sh->arg[1], "="),
			sh->sh_env[i], (ft_strlen(sh->arg[1]) + 1)) == 0)
			j = i;
		i++;
	}
	if (j == -1)
		return (sh->sh_env);
	else
	{
		if (!(new = (char**)malloc(sizeof(char*) * i)))
			return (NULL);
		while (k != j)
		{
			if (!(new[k] = ft_strdup(sh->sh_env[k])))
				return (NULL);
			k++;
		}
		while (k != (i - 1))
		{
			if (!(new[k] = ft_strdup(sh->sh_env[k + 1])))
				  return (NULL);
			k++;
		}
	}
	sh->sh_env = NULL;
	return (new);
}
