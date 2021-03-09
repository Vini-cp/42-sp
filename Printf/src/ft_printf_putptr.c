/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:41:06 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/08 21:22:45 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

int	ft_putptr(uintptr_t n)
{
	int i;

	i = 0;
	if (n > 15)
	{
		i += ft_putptr((n / 16));
		i += ft_putptr((n % 16));
	}
	else
	{
		if (n > 9)
			i += ft_putchar((n - 10 + 'a'));
		else
			i += ft_putchar((n + '0'));
	}
	return (i);
}
