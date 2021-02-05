/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:54:36 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/02 21:54:36 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memchr(const void *s, int c, unsigned int n)
{
    const unsigned char *p = s;
    while (n--)
    {
        if (*p++ == c)
            return (void *) (p - 1);
    }
    return NULL;
}
