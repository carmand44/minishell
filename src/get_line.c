/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 03:19:09 by carmand           #+#    #+#             */
/*   Updated: 2017/10/23 01:43:20 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

char	**get_line(char *buf, t_sh *sh)
{
	int i;
	int j;
	int k;
	int a;

	i = 0;
	a = 0;
	while ((buf[i] == ' ') || (buf[i] == '\t') || (buf[i] == '\n'))
		i++;
	if (buf[i] == '\0')
		return (NULL);
	while (buf[i] != '\0')
	{
		while ((buf[i] == ' ') || (buf[i] == '\t') || (buf[i] == '\n'))
			i++;
		while ((buf[i] != ' ') && (buf[i] != '\t') && (buf[i] != '\0') && (buf[i] != '\n'))
		{
			if ((buf[i + 1] == ' ') || (buf[i + 1] == '\t')
			|| (buf[i + 1] == '\0') || (buf[i + 1] == '\n'))
			{
				i++;
				a++;
				break ;
			}
			i++;
		}
		//i++;
	}
	i = 0;
	j = 0;
	if (!(sh->arg = ft_char_2d(a, ft_strlen(buf))))
		return (NULL);
	sh->s_arg = a;
	while (j != a && buf[i] != '\0' && buf[i] != '\t')
	{
		k = 0;
		while ((buf[i] == ' ') || (buf[i] == '\t'))
			i++;
		while (buf[i] != '\0' && buf[i] != ' ' && buf[i] != '\t' && buf[i] != '\n')
		{
			sh->arg[j][k] = buf[i];
			i++;
			k++;
		}
		j++;
	}
//	put_env(sh->arg, sh->s_arg);
	return (sh->arg);
}

char	**get_path(char *buf, t_sh *sh)
{
	int i;
	int j;
	int k;
	int a;
	char **path;

	i = 0;
	a = 1;
	path = NULL;
	while (buf[i] == ':')
		i++;
	if (buf[i] == '\0')
		return (NULL);
	while (buf[i] != '\0')
	{
		if (buf[i] == ':')
		{
			while (buf[i + 1] == ':')
				i++;
			if (buf[i + 1] != '\0')
				a++;
			else
				break ;
		}
		i++;
	}
	i = 0;
	j = 0;
	if (!(path = ft_char_2d(a, ft_strlen(buf))))
		return (NULL);
	sh->s_PATH = a;
	while (j != a && buf[i] != '\0')
	{
		k = 0;
		while (buf[i] == ':')
			i++;
		while (buf[i] != '\0' && buf[i] != ':' && buf[i] != '\n')
		{
			path[j][k] = buf[i];
			i++;
			k++;
		}
		j++;
	}
	return (path);
}
