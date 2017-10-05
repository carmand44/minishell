/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 21:47:15 by carmand           #+#    #+#             */
/*   Updated: 2017/10/04 22:45:21 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	exec_cd(t_sh *sh, char *path)
{
	int	i;

	i = 0;
	if (ft_strcmp(path, "..") == 0)
	{
		
	}
}

t_sh	*built_cd(t_sh *sh)
{
	int i;

	i = 0;
	if ((sh->arg[1] == NULL) || (sh->arg[2] != NULL))
	{
		while (sh->sh_env[i] != NULL)
		{
			if (ft_strncmp(sh->sh_env[i], "HOME=", 5))
			{
				exec_cd(sh, ft_strsub(sh->sh_env[i], 5, \
							(ft_strlen(sh->sh_env[i]) - 5)));
				break ;
			}
			i++;
		}
	}
	else
		exec_cd(sh , sh->arg[1]);
	return (sh);
}
