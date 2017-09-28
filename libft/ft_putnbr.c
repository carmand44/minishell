/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:24:11 by carmand           #+#    #+#             */
/*   Updated: 2016/11/30 21:34:19 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	txtspc[11];
	char	*ntxt;

	if (n == 0)
		return (ft_putchar('0'));
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	ntxt = &txtspc[10];
	*ntxt = '\0';
	if (n < 0 && (n *= -1))
		ft_putchar('-');
	while (n > 0)
	{
		*(--ntxt) = 48 + (n % 10);
		n = n / 10;
	}
	ft_putstr(ntxt);
}
