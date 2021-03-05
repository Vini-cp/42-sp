/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putunbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:39:26 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/04 23:39:33 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putunbr(unsigned int n)
{
	if (n > 9)
	{
		ft_putunbr((n / 10));
		ft_putunbr((n % 10));
	}
	else
		ft_putchar((n + '0'));
}
