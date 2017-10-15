/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 22:51:28 by carmand           #+#    #+#             */
/*   Updated: 2017/10/16 00:47:06 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"



t_sh	*cd(t_sh *sh)
{
	if (sh->arg[1] != NULL)
		if (!(sh->arg[1] = ft_strdup(sh->HOME)))
				return (NULL);
	ft_strdel(&sh->OLDPWD);
	ft_strdel(&sh->PWD);
	if (!(sh->OLDPWD = get_pwd()))
		return (NULL);
	ft_putendl(sh->OLDPWD);	
	return (sh);
}
