/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:36:15 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/09 10:19:09 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

char	*ft_itoa(int num)
{ 
	int i;
	int isNegative;
	char *str;

	if (num == 0)
		return (str = ft_strdup("0\0"));
	else if (num == -2147483648)
		return (str = ft_strdup("-2147483648\0"));
	i = 0;
	str = (char *)malloc(12 * sizeof(char));
	isNegative = (num < 0)? 1 : 0;
	num *= (isNegative)? -1 : 1;
	while (num != 0)
	{
		str[i++] = num % 10 + '0';
		num = num / 10;
	}
	if (isNegative)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
