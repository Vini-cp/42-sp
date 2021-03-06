/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:03:31 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/05 23:53:37 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
		i += ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			i += ft_putchar('-');
			n = n * (-1);
		}
		if (n > 9)
		{
			i += ft_putnbr((n / 10));
			i += ft_putnbr((n % 10));
		}
		else
			i += ft_putchar((n + '0'));
	}
	return (i);
}
