/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 00:23:47 by carmand           #+#    #+#             */
/*   Updated: 2017/10/16 01:14:43 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void		free_tab(char **tab)
{
	int	i;

	i = 0;
	ft_putchar('Z');
	if (tab != NULL)
	{
		while (tab[i])
		{
			ft_putchar('P');
			ft_strdel(&tab[i]);
			i++;
		}
		ft_putchar('K');
		free(tab);
	}
}

void		free_sh(t_sh *sh)
{
	ft_putchar('Q');
	free_tab(sh->sh_env);
	ft_putchar('a');
	free_tab(sh->PATH);
	ft_putchar('b');
	free_tab(sh->arg);
	ft_putchar('c');
	ft_strdel(&sh->PWD);
	ft_putchar('d');
	ft_strdel(&sh->OLDPWD);
	ft_putchar('e');
	ft_strdel(&sh->HOME);
	ft_putchar('f');
	ft_strdel(&sh->BUF);
	ft_putchar('g');
	free(sh);
	ft_putchar('h');
}
