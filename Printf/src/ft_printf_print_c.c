/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:45:20 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/14 14:51:45 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

static	int	print_just(to_print *lst)
{
	lst->str = (lst->prec == 0 && ft_atoi(lst->str) == 0)? NULL : lst->str;
	lst->s_len = (lst->str)? lst->s_len : 0;
	if (lst->prec > lst->s_len)
		ft_putstr_fd(ft_substr(lst->f, 0, lst->prec - lst->s_len), 1);
	ft_putchar_fd(lst->print_c, 1);
	if (lst->prec > 0)
	{
		if (lst->width > ft_max(lst->prec, lst->s_len))
			ft_putstr_fd(ft_substr(lst->spaces, 0, \
			lst->width - ft_max(lst->prec, lst->s_len)), 1);
	}
	else
	{
		if (lst->width > lst->s_len)
			ft_putstr_fd(ft_substr(lst->spaces, 0, lst->width - lst->s_len), 1);
	}
	return (ft_max(ft_max(lst->prec, lst->s_len), lst->width));
}

static	int	print_not_just(to_print *lst)
{
	lst->str = (lst->prec == 0 && ft_atoi(lst->str) == 0)? NULL : lst->str;
	lst->s_len = (lst->str)? lst->s_len : 0;
	if (lst->prec > 0)
	{
		if (lst->prec > lst->s_len)
		{
			if (lst->width > lst->prec)
				ft_putstr_fd(ft_substr(lst->spaces, 0, lst->width - lst->prec), 1);
			ft_putstr_fd(ft_substr(lst->f, 0, lst->prec - lst->s_len), 1);
		}
		else if (lst->width > lst->s_len)
			ft_putstr_fd(ft_substr(lst->spaces, 0, lst->width - lst->s_len), 1);
		ft_putchar_fd(lst->print_c, 1);
	}
	else
	{
		if (lst->zero)
			if (lst->width > lst->s_len)
				ft_putstr_fd(ft_substr(lst->f, 0, lst->width - lst->s_len), 1);
		if (!lst->zero)
			if (lst->width > lst->s_len)
				ft_putstr_fd(ft_substr(lst->spaces, 0, lst->width - lst->s_len), 1);
		ft_putchar_fd(lst->print_c, 1);
	}
	return (ft_max(ft_max(lst->prec, lst->s_len), lst->width));
}

int 		ft_printf_print_c(to_print *lst)
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
