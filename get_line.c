/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 03:19:09 by carmand           #+#    #+#             */
/*   Updated: 2017/09/30 21:23:43 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

t_sh	*get_line(char *buf, t_sh *sh)
{
	int i;
	int j;
	int k;
	int a;
	
	i = 0;
	a = 1;
	while ((buf[i] == ' ') || (buf[i] == '\t'))
		i++;
	if (buf[i] == '\0')
		return (NULL);
	while (buf[i] != '\0')
	{
		if ((buf[i] == ' ') || (buf[i] == '\t'))
		{
			while ((buf[i + 1] == ' ') || (buf[i + 1] == '\t'))
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
	if (!(sh->arg = ft_char_2d(a, ft_strlen(buf))))
		return (NULL);
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
	return (sh);
}
