/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:11:47 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 17:27:13 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
