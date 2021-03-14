/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:22:35 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/14 18:19:15 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

char	*ft_ptoa(uintptr_t num, int prec)
{
	int			i;
	uintptr_t	rem;
	char		*s;

	if (num == 0 && prec != 0)
		return (s = ft_strdup("0x0\0"));
	else if (num == 0 && prec == 0)
		return (s = ft_strdup("0x\0"));
	i = 0;
	s = (char *)malloc(9 * sizeof(char));
	while (num != 0)
	{
		rem = num % 16;
		s[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / 16;
	}
	s[i++] = 'x';
	s[i++] = '0';
	s[i] = '\0';
	ft_strrev(s);
	return (s);
}
