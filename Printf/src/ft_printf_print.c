/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:30:32 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/15 20:10:25 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

static	int	print_just(t_flags *lst)
{
	if (lst->prec > lst->s_len)
		ft_putstr_fd(ft_substr(lst->f, 0, lst->prec - lst->s_len), 1);
	ft_putstr_fd(lst->str, 1);
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

static	int	print_not_just(t_flags *lst)
{
	if (lst->prec >= 0)
	{
		if (lst->prec > lst->s_len)
		{
			if (lst->width > lst->prec)
				ft_putstr_fd(ft_substr(lst->spaces, 0, \
				lst->width - lst->prec), 1);
			ft_putstr_fd(ft_substr(lst->f, 0, lst->prec - lst->s_len), 1);
		}
		else if (lst->width > lst->s_len)
			ft_putstr_fd(ft_substr(lst->spaces, 0, lst->width - lst->s_len), 1);
		ft_putstr_fd(lst->str, 1);
	}
	else
	{
		if (lst->zero)
			if (lst->width > lst->s_len)
				ft_putstr_fd(ft_substr(lst->f, 0, lst->width - lst->s_len), 1);
		if (!lst->zero && (lst->width > lst->s_len))
			ft_putstr_fd(ft_substr(lst->spaces, 0, lst->width - lst->s_len), 1);
		ft_putstr_fd(lst->str, 1);
	}
	return (ft_max(ft_max(lst->prec, lst->s_len), lst->width));
}

static	int	print_neg_just(t_flags *lst)
{
	if (lst->prec > lst->s_len - 1)
	{
		ft_putchar_fd('-', 1);
		ft_putstr_fd(ft_substr(lst->f, 0, lst->prec - lst->s_len + 1), 1);
		ft_putstr_fd(ft_substr(lst->str, 1, ft_strlen(lst->str)), 1);
	}
	else
		ft_putstr_fd(lst->str, 1);
	if (lst->prec >= 0)
	{
		if (lst->width > ft_max(lst->prec + 1, lst->s_len))
			ft_putstr_fd(ft_substr(lst->spaces, 0, \
			lst->width - ft_max(lst->prec + 1, lst->s_len)), 1);
	}
	else
	{
		if (lst->width > lst->s_len)
			ft_putstr_fd(ft_substr(lst->spaces, 0, lst->width - lst->s_len), 1);
	}
	return (ft_max(ft_max(lst->prec + 1, lst->s_len), lst->width));
}

static	int	print_neg_not_just(t_flags *lst)
{
	if (lst->prec >= 0)
	{
		if (lst->width > ft_max(lst->prec + 1, lst->s_len))
			ft_putstr_fd(ft_substr(lst->spaces, 0, \
			lst->width - ft_max(lst->prec + 1, lst->s_len)), 1);
		ft_putchar_fd('-', 1);
		if (lst->prec > lst->s_len - 1)
			ft_putstr_fd(ft_substr(lst->f, 0, lst->prec - lst->s_len + 1), 1);
		ft_putstr_fd(ft_substr(lst->str, 1, ft_strlen(lst->str)), 1);
	}
	else if (lst->width > lst->s_len && !lst->zero)
	{
		ft_putstr_fd(ft_substr(lst->spaces, 0, lst->width - lst->s_len), 1);
		ft_putstr_fd(lst->str, 1);
	}
	else if (lst->width > lst->s_len && lst->zero)
	{
		ft_putchar_fd('-', 1);
		ft_putstr_fd(ft_substr(lst->f, 0, lst->width - lst->s_len), 1);
		ft_putstr_fd(ft_substr(lst->str, 1, ft_strlen(lst->str)), 1);
	}
	else
		ft_putstr_fd(lst->str, 1);
	return (ft_max(ft_max(lst->prec + 1, lst->s_len), lst->width));
}

int			ft_printf_print(t_flags *lst)
{
	if (lst->prec == 0 && lst->str[0] == '0')
	{
		lst->str = "\0";
		lst->s_len = 0;
		lst->zero = 0;
	}
	if (lst->str && ft_atoi(lst->str) < 0 && lst->c != 'u')
	{
		if (lst->just)
			return (print_neg_just(lst));
		else
			return (print_neg_not_just(lst));
	}
	else if (lst->c == 'c')
		return (ft_printf_print_c(lst));
	else
	{
		if (lst->just)
			return (print_just(lst));
		else
			return (print_not_just(lst));
	}
}
