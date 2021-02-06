/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:54:36 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 15:32:04 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void    *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *p;
    
    p = (const unsigned char *) s;
    while (n--)
    {
        if (*p++ == (unsigned char) c)
            return (void *) (p - 1);
    }
    return NULL;
}
