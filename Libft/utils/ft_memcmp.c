/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:54:38 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/02 22:01:11 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
    char *cs1;
    char *cs2;

    *cs1 = (char *)s1;
    *cs2 = (char *)s2;
    while (n--)
    {
        if (*cs1++ != *cs2++)
            return (*(cs1 - 1) - *(cs2 - 1));
    }
    return (0);
}
