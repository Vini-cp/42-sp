/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:54:43 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/04 23:36:33 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    while (n--)
        *cdest++ = *csrc++;
    return dest;
}

// int main () {
//    char dest[] = "oldstring";
//    const char src[]  = "newstring";

//    printf("Before memmove dest = %s, src = %s\n", dest, src);
//    ft_memmove(dest, src, 9);
//    printf("After memmove dest = %s, src = %s\n", dest, src);

//    return(0);
// }
