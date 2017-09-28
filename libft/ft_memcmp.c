/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2016/11/30 18:23:33 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmps1;
	unsigned char	*tmps2;

	tmps1 = (unsigned char*)s1;
	tmps2 = (unsigned char*)s2;
	if (s1 == s2)
		return (0);
	while (n--)
	{
		if (*tmps1 != *tmps2)
			return (*tmps1 - *tmps2);
		tmps1++;
		tmps2++;
	}
	return (0);
}
