/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:41:06 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/04 23:41:08 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putptr(uintptr_t n)
{
	if (n > 15)
	{
		ft_putptr((n / 16));
		ft_putptr((n % 16));
	}
	else
	{
		if (n > 9)
			ft_putchar((n - 10 + 'a'));
		else
			ft_putchar((n + '0'));
	}
}
