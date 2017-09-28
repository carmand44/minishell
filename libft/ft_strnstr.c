/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 03:19:32 by carmand           #+#    #+#             */
/*   Updated: 2016/11/30 21:50:08 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *m, const char *n, size_t len)
{
	unsigned int	i;
	unsigned int	pos;
	size_t			slen;

	i = 0;
	slen = ft_strlen(n);
	if (slen == 0)
		return ((char*)m);
	while (m[i] && (slen + i) <= len)
	{
		pos = 0;
		while (n[pos] == m[pos + i])
		{
			if (pos == (slen - 1))
				return ((char*)m + i);
			pos++;
		}
		i++;
	}
	return (NULL);
}
