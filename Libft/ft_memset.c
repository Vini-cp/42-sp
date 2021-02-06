/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:54:46 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/04 23:36:45 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char *p = s;
    while (n--)
        *p++ = c;
    return s;
}
