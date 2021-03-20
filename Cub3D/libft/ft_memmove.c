/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:54:43 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/19 20:43:05 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*cdst;
	const char	*csrc;

	cdst = dest;
	csrc = src;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		while (n--)
			*cdst++ = *csrc++;
	else
	{
		csrc = csrc + (n - 1);
		cdst = cdst + (n - 1);
		while (n--)
			*cdst-- = *csrc--;
	}
	return (dest);
}
