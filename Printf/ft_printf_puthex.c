/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 20:30:29 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/05 23:54:00 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthex(unsigned int n, int bool_lower)
{
	int i;

	i = 0;
	if (n > 15)
	{
		i += ft_puthex((n / 16), bool_lower);
		i += ft_puthex((n % 16), bool_lower);
	}
	else
	{
		if (n > 9)
			if (bool_lower)
				i += ft_putchar((n - 10 + 'a'));
			else
				i += ft_putchar((n - 10 + 'A'));
		else
			i += ft_putchar((n + '0'));
	}
	return (i);
}
