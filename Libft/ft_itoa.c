/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:36:15 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/07 13:19:05 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static  char    *int_to_str(char *s, unsigned int nb, int neg);
static  void    rev_array(char *str, int len);
static  int     check_neg(int n);

char    *ft_itoa(int n)
{
    int             neg;
    unsigned int	nb;
    char            *s;
    
    neg = check_neg(n);
    if (neg)
        nb = n * (-1);
    else
        nb = n;
    if(!(s = (char *) malloc(12 * sizeof(char))))
        return NULL;
    if (nb == 0)
    {
        s[0] = '0';
        s[1] = '\0';
        return s;
    }
    return int_to_str(s, nb, neg);
}

static  char    *int_to_str(char *s, unsigned int nb, int neg)
{
    int     len;
       
    len = 0;
    while (nb)
    {
        *s++ = nb%10 + '0';
        nb = (nb - nb%10)/10;
        len++;
    }
    if (neg)
    {
        *s++ = '-';
        len++;
    }
    *s = '\0';
    rev_array(s - len, len);
    return s - len;
}

static  void    rev_array(char *str, int len)
{
	int		i;
	char	c;

	i = 0;
	while (i < len / 2)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		i++;
	}
}

static  int check_neg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}
