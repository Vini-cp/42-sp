/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:45:20 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/14 22:34:32 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

static	int	print_just(to_print *lst)
{
	if (lst->width > 0)
	{
		ft_putchar_fd(lst->print_c, 1);
		ft_putstr_fd(ft_substr(lst->spaces, 0, lst->width - 1), 1);
	}
	else
		ft_putchar_fd(lst->print_c, 1);
	return (ft_max(1, lst->width));
}

static	int	print_not_just(to_print *lst)
{
	if (lst->width > 0)
	{
		if (lst->print_c == '%' && lst->zero)
			ft_putstr_fd(ft_substr(lst->f, 0, lst->width - 1), 1);
		else
			ft_putstr_fd(ft_substr(lst->spaces, 0, lst->width - 1), 1);
		ft_putchar_fd(lst->print_c, 1);
	}
	else
		ft_putchar_fd(lst->print_c, 1);
	return (ft_max(1, lst->width));
}

int			ft_printf_print_c(to_print *lst)
{
	int i;

	i = 0;
	lst->s_len = 1;
	if (lst->just)
		i = print_just(lst);
	else
		i = print_not_just(lst);
	return (i);
}
