/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2016/11/29 18:27:37 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	n;
	char	*dup;

	i = 0;
	n = ft_strlen(src);
	dup = (char*)malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (NULL);
	else
	{
		while (src[i] != '\0' && i < n)
		{
			dup[i] = src[i];
			i++;
		}
		dup[i] = '\0';
		return (dup);
	}
}
