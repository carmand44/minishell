/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2016/11/30 20:35:40 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_digitc(int n)
{
	int		count;
	long	tens;

	count = 1;
	tens = 10;
	if (n < 0)
		n = n * -1;
	while (n >= tens)
	{
		tens = tens * 10;
		count++;
	}
	return (count);
}

static char		*ft_n_neg(int *n, int *charnum, int *lastnum, char *ntxt)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*charnum = *charnum + 1;
		*lastnum = *lastnum + 1;
		ntxt = ft_strnew(*charnum);
		if (!ntxt)
			return (NULL);
		ntxt[0] = '-';
	}
	else
	{
		ntxt = ft_strnew(*charnum);
		if (!ntxt)
			return (NULL);
	}
	return (ntxt);
}

char			*ft_itoa(int n)
{
	char	*ntxt;
	int		charnum;
	int		lastnum;

	ntxt = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	charnum = ft_digitc(n);
	lastnum = 0;
	ntxt = ft_n_neg(&n, &charnum, &lastnum, ntxt);
	if (!ntxt)
		return (NULL);
	charnum--;
	while (charnum >= lastnum)
	{
		ntxt[charnum--] = (n % 10) + 48;
		n = n / 10;
	}
	return (ntxt);
}
