/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/10/04 02:00:59 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	exec(t_sh *sh, char *bin)
{
	pid_t father;

	father = fork();
	if (father > 0)
		wait (0);
	if (father == 0)
	{
		execve(bin, sh->arg, sh->sh_env);
		write(2, ft_strjoin("minishell: command not found: ", \
				   	ft_strjoin(bin, "\n")), (ft_strlen(bin) + 32));
	}
}
