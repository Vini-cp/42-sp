/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:52:42 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/04 22:48:04 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
