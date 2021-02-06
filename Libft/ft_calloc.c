/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 01:25:50 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 01:32:30 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static  void    *ft_memset(void *s, int c, size_t n);

void    *ft_calloc(size_t nelem, size_t elsize)
{
    void *p;
    
    p = ft_memset(malloc(nelem * elsize), 0, nelem);
    return p;
}

static  void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char *p = s;
    while (n--)
        *p++ = c;
    return s;
}