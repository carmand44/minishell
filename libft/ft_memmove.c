/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2016/11/30 18:27:30 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c_dst;
	unsigned char	*c_src;

	c_dst = (unsigned char*)dst;
	c_src = (unsigned char*)src;
	i = -1;
	if (c_src < c_dst)
		while ((int)(--n) >= 0)
			*(c_dst + n) = *(c_src + n);
	else
		while (++i < n)
			*(c_dst + i) = *(c_src + i);
	return (dst);
}
