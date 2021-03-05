/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 20:30:29 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/04 20:31:24 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthex(unsigned int n, int bool_lower)
{
	if (n > 15)
	{
		ft_puthex((n / 16), bool_lower);
		ft_puthex((n % 16), bool_lower);
	}
	else
	{
		if (n > 9)
			if (bool_lower)
				ft_putchar((n - 10 + 'a'));
			else
				ft_putchar((n - 10 + 'A'));
		else
			ft_putchar((n + '0'));
	}
}
