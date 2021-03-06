/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:58:33 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/08 21:22:45 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char c1;

	c1 = ' ';
	while (c1 != '\0')
	{
		c1 = (unsigned char)*s++;
		if (c1 == c)
			return (char *)(s - 1);
	}
	return (NULL);
}
