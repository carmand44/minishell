/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 23:39:08 by carmand           #+#    #+#             */
/*   Updated: 2017/09/28 05:07:17 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

int		main(int a, char **v)
{

	size_t ret;
	char *buf;
	char *exit;
	char *bin;
	t_sh *sh;
	pid_t father;

	if (!(sh = (t_sh*)malloc(sizeof(t_sh))))
		return (0);
	sh->arg = NULL;
	sh->bin_tmp = NULL;
	if (!(exit = ft_strdup("exit\n")))
		return (0);
	if (!(bin = ft_strdup("/bin/")))
		return (0);
	buf = ft_strnew(128);
	while(42)
	{
		ft_putstr("$> ");
		if (sh->arg != NULL)
		{
			sh->arg = NULL;
			sh->bin_tmp = NULL;
		}
		if ((ret = read(0, buf, 128)))
		{
			buf[ret] = '\0';
			if (strcmp(buf, exit) == 0)
				return (1);
			father = fork();
			if (father > 0)
				wait(0);
			if (father == 0)
				execve(ft_strjoin(bin, buf), v, NULL);
		}
	}
	a++;
	return (1);
}
