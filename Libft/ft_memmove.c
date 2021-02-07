/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:54:43 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 17:22:02 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    void *interm;
    interm = (void *)malloc(sizeof(void));

    ft_memcpy(interm, src, n);
    ft_memcpy(dest, (const void *) interm, n);
    return dest;
}
