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

int		main(void)
{

	size_t ret;
	char *buf;
	char *bin;
	char *path;
	t_sh *sh;
	pid_t father;
	int i;

	path = ft_strnew(128);
	i = 1;
	while (!(path = getcwd(path, 128 * i)))
	{
		path = NULL;
		path = ft_strnew(128 * i);
		i++;
	}
	ft_putendl(path);
	if (!(sh = (t_sh*)malloc(sizeof(t_sh))))
		return (0);
	if (!(bin = ft_strdup("/bin/")))
		return (0);
	buf = ft_strnew(128);
	while(42)
	{
		ft_putstr("$> ");
		sh->arg = NULL;
		if ((ret = read(0, buf, 128)))
		{
			buf[ret] = '\0';
			if (!(sh = get_line(buf, sh)))
				return (0);
			father = fork();
			if (father > 0)
				wait(0);
			if (father == 0)
				execve(ft_strjoin(bin, sh->arg[0]), sh->arg, NULL);
		}
	}
	return (1);
}
