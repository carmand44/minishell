/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 03:19:32 by carmand           #+#    #+#             */
/*   Updated: 2016/11/30 18:53:38 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *m, const char *n)
{
	size_t	i;
	size_t	pos;
	size_t	len;

	i = 0;
	len = ft_strlen(n);
	if (len == 0)
		return ((char*)m);
	while (m[i])
	{
		pos = 0;
		while (n[pos] == m[pos + i])
		{
			if (pos == (len - 1))
				return ((char*)m + i);
			pos++;
		}
		i++;
	}
	return (NULL);
}
