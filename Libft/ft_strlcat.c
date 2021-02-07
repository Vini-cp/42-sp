/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 01:50:02 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 17:26:22 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
	size_t j;
    
    if (size <= ft_strlen(dst))
        return (ft_strlen(src) + size);
	i = 0;
	while (dst[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (i + j < size - 1 && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	return (i + j);
}
