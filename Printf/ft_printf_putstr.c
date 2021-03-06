/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:14:22 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/06 16:29:11 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *s)
{
	int i;

	i = ft_strlen(s);
	if (s)
		while (*s != '\0')
			ft_putchar(*s++);
	return (i);
}
