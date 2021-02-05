/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:54:41 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/02 21:54:42 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memcpy(void *dest, const void *src, unsigned int n)
{
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    while (n--)
        *cdest++ = *csrc++;
    return dest;
}
