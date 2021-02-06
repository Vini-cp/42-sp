/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:35:21 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 13:53:48 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

// static  size_t	ft_strlen(const char *s);
static  size_t	strlen_without_set(const char *s, char const *set);

char *ft_strtrim(char const *s1, char const *set)
{
    char    *str;
    int     len;
    int     i;
    int     j;
    int     bool_check;

    i = 0;
    len = strlen_without_set(s1, set);
    if(!(str = malloc(len * sizeof(char))))
        return NULL;
    while (s1[i] != '\0')
	{
        j = 0;
        bool_check = 1;
        while (set[j] != '\0' && bool_check)
		{
            if (set[j] == s1[i])
                bool_check = 0;
            j++;
        }
        if (bool_check)
            *str++ = s1[i];
        i++; 
	}
    return str - len;
}

static  size_t	strlen_without_set(const char *s, char const *set)
{
	size_t  length;
    int     i;
    int     j;
    int     bool_check;

    i = 0;
    length = 0;
	while (s[i] != '\0')
	{
        j = 0;
        bool_check = 1;
        while (set[j] != '\0' && bool_check)
		{
            if (set[j] == s[i])
                bool_check = 0;
            j++;
        }
        if (bool_check)
            length++;
        i++; 
	}
	return (length);
}

// static  size_t	ft_strlen(const char *s)
// {
// 	size_t length;

// 	length = 0;
// 	while (s[length] != '\0')
// 	{
// 		length++;
// 	}
// 	return (length);
// }

// int main()
// {
//     char str[] = "Oi, eu sou o Goku!";
//     char set[] = " o";
    
//     printf("%zu\n", ft_strlen(str));
//     printf("%zu\n", strlen_without_set(str, set));
//     printf("%s\n", str);
//     printf("%s\n", ft_strtrim(str, set));
// }