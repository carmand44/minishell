/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2016/11/30 19:38:51 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	new = NULL;
	new = (char*)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = '\0';
		i++;
	}
	new[i] = '\0';
	return (new);
}
