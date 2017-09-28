/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 05:10:39 by carmand           #+#    #+#             */
/*   Updated: 2016/11/30 18:54:23 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, char c)
{
	int		i;
	char	*last;

	if (c == '\0')
		return ((char*)str + ft_strlen(str));
	last = (char*)'\0';
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			last = (char*)str + i;
		i++;
	}
	return (last);
}
