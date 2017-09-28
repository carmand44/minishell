/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2016/12/01 03:06:10 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**wary_init(char const *s, char c)
{
	long long		i;
	long long		beg;
	char			**wary;
	unsigned int	wcount;

	wcount = 0;
	beg = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (beg != i - 1)
				wcount++;
			beg = i;
		}
		i++;
	}
	if (beg != i - 1)
		wcount++;
	wary = (char **)malloc((wcount + 1) * sizeof(char*));
	if (!wary)
		return (NULL);
	wary[wcount] = NULL;
	return (wary);
}

char			**ft_strsplit(char const *s, char c)
{
	long long		i;
	long long		beg;
	char			**wary;
	unsigned int	wcount;

	if (!s || !(wary = wary_init((char*)s, c)))
		return (NULL);
	wcount = 0;
	beg = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (beg != i - 1)
				wary[wcount++] = ft_strsub((char*)s, beg + 1, (i - beg) - 1);
			beg = i;
		}
		i++;
	}
	if (beg != i - 1)
		wary[wcount++] = ft_strsub((char*)s, beg + 1, (i - beg) - 1);
	return (wary);
}
