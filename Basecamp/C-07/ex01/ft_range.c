/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 01:13:14 by vcordeir          #+#    #+#             */
/*   Updated: 2020/12/04 01:37:58 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *p;
	int i;
	int len;

	if (min >= max)
		return (NULL);
	len = max - min;
	if (!(p = malloc(len * sizeof(*p))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = max - i - 1;
		i++;
	}
	return (p);
}
