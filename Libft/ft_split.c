/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 23:22:30 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 00:57:53 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char    **ft_split(char const *s, char c)
{
    int     i;
    int     j;
    int     nb;
    int     *p;
    char    **strs;

    i = 0;
    nb = nb_of_strs(s, c);
    if(!(strs = (char**) malloc(nb * sizeof(char*))))
        return(NULL);
    p = str_len(s, c, nb);
    while(i < nb)
        strs[i] = (char*) malloc(p[i] * sizeof(char))
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            bool_check = 1;
            i++;   
        }
        else if(s[i] != c && bool_check)
        {
            p[j] = 1;
            while(s[i] != c && s[i] != '\0')
            {
                p[j]++;
                i++;
            }
            j++;
            bool_check = 0;
        }
    }
    return strs;
}

int		ft_strlen(char const *str)
{
	int length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

int     nb_of_strs(char const *s, char c)
{
    int i;
    int nb;
    int bool_check;
    
    i = 0;
    nb = 0;
    bool_check = 1;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            bool_check = 1;
        else if(s[i] != c && bool_check)
        {
            nb++;
            bool_check = 0;
        }
        i++;
    }
    return nb;
}

int     *strs_len(char const *s, char c, int nb)
{
    int i;
    int j;
    int *p;
    int bool_check;
    
    p = (int*) malloc(nb * sizeof(int));
    i = 0;
    j = 0;
    bool_check = 1;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            bool_check = 1;
            i++;   
        }
        else if(s[i] != c && bool_check)
        {
            p[j] = 1;
            while(s[i] != c && s[i] != '\0')
            {
                p[j]++;
                i++;
            }
            j++;
            bool_check = 0;
        }
    }
    return p;
}

int main()
{
	char str[] = "Hy! my name is Vinicius!";
    // int len = ft_strlen(str);
    int nb = nb_of_strs(str, ' ');
    printf("%d\n\n", nb);
    int *p = strs_len(str, ' ', nb);
    int i = 0;
    while (i < 5)
    {
        printf("%d\n", p[i]);
        i++;
    }
}

