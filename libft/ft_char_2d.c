/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/04/25 20:44:51 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_char_2d(int it, int jt)
{
	int		i;
	char	**tab;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * (it + 1));
	if (!tab)
		return (NULL);
	while (i < it)
	{
		tab[i] = (char*)ft_memalloc(sizeof(char) * (jt + 1));
		if (tab[i] == NULL)
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
