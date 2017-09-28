/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 03:19:09 by carmand           #+#    #+#             */
/*   Updated: 2017/09/28 05:07:35 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_sh	*get_line(char *buf, t_sh *sh);
{
	int i;
	int a;

	i = 0;
	a = 1;
	while (buf[i] == ' ')
		i++;
	while (buf[i] != '\0')
	{
		if (buf[i] == ' ')
		{
			a++
			while (buf[i] == ' ')
				i++;
		}
		i++;
	}
	if (a == 1)
	{
		sh->arg == ft_char_2d(a, ft_strlen(buf));
		bin_tmp == ft_strdup(buf);
		return (sh);
	}
	

}
