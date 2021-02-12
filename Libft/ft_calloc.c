/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 01:25:50 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/11 23:16:03 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void *p;

	if (nelem == 0 || elsize == 0)
	{
		nelem = 1;
		elsize = 1;
	}
	if (!(p = malloc(nelem * elsize)))
		return (NULL);
	p = ft_memset(p, 0, nelem);
	return (p);
}
