/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:32:15 by carmand           #+#    #+#             */
/*   Updated: 2017/10/05 22:48:40 by carmand          ###   ########.fr       */
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

void	set_env(t_sh *sh)
{
	char **new;
	int i;

	i = 0;
	while (sh->sh_env[i] != NULL)
	{
		if (ft_strncmp(ft_strjoin(sh->arg[1], sh->sh_env[i], 5) == 0)
		i++;
	}
}
