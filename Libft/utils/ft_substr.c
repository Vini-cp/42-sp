/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:52:42 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/04 23:41:12 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str;
    unsigned int i;

    str = (char*) malloc(len*sizeof(char));
    i = start;
    while(s[i] != '\0' && len--)
    {
        str[i - start] = s[i];
        i++;
    }
    return str;
}
