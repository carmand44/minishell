/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2016/11/30 19:52:43 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	new = NULL;
	i = 0;
	if (!s || !f)
		return (NULL);
	new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (0);
	while (s[i] != '\0')
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
