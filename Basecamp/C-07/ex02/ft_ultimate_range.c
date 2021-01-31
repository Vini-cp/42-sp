/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:52:34 by vcordeir          #+#    #+#             */
/*   Updated: 2020/12/04 01:48:33 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int len;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	len = max - min;
	if (!(*range = (int *)malloc(sizeof(int) * len)))
	{
		return (-1);
	}
	i = 0;
	while (i < len)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}
