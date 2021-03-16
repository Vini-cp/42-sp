/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_newflag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 21:38:50 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/15 21:39:48 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

t_flags	*ft_printf_newflag(void)
{
	t_flags *lst;

	lst = (t_flags *)malloc(sizeof(t_flags));
	lst->f = NULL;
	lst->str = NULL;
	lst->spaces = NULL;
	lst->just = 0;
	lst->prec = -1;
	lst->width = 0;
	lst->zero = 0;
	return (lst);
}