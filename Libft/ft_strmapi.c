/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:06:25 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/10 21:39:18 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
