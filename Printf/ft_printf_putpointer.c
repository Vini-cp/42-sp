/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putpointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:03:29 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/04 21:08:47 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putpointer(uintptr_t n)
{
	if (n > 15)
	{
		ft_putpointer((n / 16));
		ft_putpointer((n % 16));
	}
	else
	{
		if (n > 9)
			ft_putchar((n - 10 + 'a'));
		else
			ft_putchar((n + '0'));
	}
}
