/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_empty_zeros.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:17:42 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/15 18:45:33 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

void	ft_printf_empty_zeros(to_print **lst)
{
	char	*s;
	char	*t;
	int		i;
	int		size;

	(*lst)->just = ((*lst)->width < 0) ? 1 : (*lst)->just;
	(*lst)->width *= ((*lst)->width < 0) ? -1 : 1;
	size = ((*lst)->width >= (*lst)->prec) ? (*lst)->width : (*lst)->prec;
	s = (char *)malloc((size + 1) * sizeof(char));
	t = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	while (i < size)
	{
		s[i] = '0';
		t[i] = ' ';
		i++;
	}
	s[i] = '\0';
	t[i] = '\0';
	(*lst)->f = ft_strdup(s);
	(*lst)->spaces = ft_strdup(t);
}
