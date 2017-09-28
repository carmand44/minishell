/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:15:37 by carmand           #+#    #+#             */
/*   Updated: 2016/11/30 18:51:47 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;
	unsigned char	*sa;
	unsigned char	*sb;

	sa = (unsigned char*)s1;
	sb = (unsigned char*)s2;
	i = 0;
	while (sa[i] != '\0' && sb[i] != '\0')
	{
		if (sa[i] != sb[i])
			return (sa[i] - sb[i]);
		i++;
	}
	if (sa[i] == sb[i])
		return (0);
	return (sa[i] - sb[i]);
}
