/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:01:32 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/09 10:14:25 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

char	*ft_utoa(size_t num, int base, int capitalize)
{ 
    int		i;
	size_t	rem;
	char	*s;
	char	c;

    if (num == 0)
		return (s = ft_strdup("0\0"));
	c = (capitalize)? 'A' : 'a';
	i = 0;
	s = (char *)malloc(9 * sizeof(char));
    while (num != 0)
    {
        rem = num % base;
        s[i++] = (rem > 9)? (rem - 10) + c : rem + '0';
        num = num / base;
    }
    s[i] = '\0';
    ft_strrev(s);
    return (s);
}

// int main()
// {
// 	char *s;
// 	s = ft_utoa(4294967295);
// 	printf("%s\n", s);
// }