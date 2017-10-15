/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_sh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 23:49:40 by carmand           #+#    #+#             */
/*   Updated: 2017/10/16 00:45:33 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

char	*get_pwd(void)
{
	char	*pwd;
	int		i;

	pwd = NULL;
	i = BUFF_SIZE;
	if (!(pwd = ft_strnew(i)))
		return (NULL);
	while (getcwd(pwd, i) == NULL)
	{
		ft_strdel(&pwd);
		i += BUFF_SIZE;
		if (!(pwd = ft_strnew(i)))
			return (NULL);
	}
	return (pwd);
}

int		search_env(char **env, char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = -1;
	tmp = NULL;
	if (!(tmp = ft_strjoin(str, "=")))
		return (-2);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], tmp, ft_strlen(tmp)) == 0)
			j = i;
		i++;
	}
	ft_strdel(&tmp);
	return (j);
}
