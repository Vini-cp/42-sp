/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:06:25 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 13:33:36 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static  size_t	ft_strlen(const char *s);

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *str;
    int     len;
    int     i;

    i = 0;
    len = ft_strlen(s);
    if(!(str = malloc(len * sizeof(char))))
        return NULL;
    while(i < len)
    {
        str[i] = f((unsigned int) i, s[i]);
        i++;
    }
    return str;
}

static  size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
