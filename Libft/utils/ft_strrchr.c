/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:11:47 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 11:41:54 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t  ft_strlen(const char *s);

char    *ft_strrchr(const char *s, int c)
{
    char    *str;
    int     len;
    
    str = (char *) s;
    len = ft_strlen(s);
    str += (len);
    while (len-- >= 0)
    {
        if (*str-- == c)
            return (char *) (str + 1);
    }
    return NULL;
}

static size_t  ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
