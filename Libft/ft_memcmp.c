/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:54:38 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/10 22:43:10 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *str1;
	const unsigned char *str2;

	str1 = (const unsigned char*)s1;
	str2 = (const unsigned char*)s2;
	while (n--)
	{
		if (*str1++ != *str2++)
			return (*(str1 -1) - *(str2 - 1));
	}
	return (0);
}
