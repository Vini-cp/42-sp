/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_p_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 01:00:12 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/15 20:07:13 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

static	int	print_p_just(t_flags *lst)
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

static	int	print_p_not_just(t_flags *lst)
{
	if (lst->prec > lst->s_len)
	{
		if (lst->prec > 0)
		{
			ft_putstr_fd(ft_substr(lst->spaces, 0, lst->width - lst->prec), 1);
			ft_putstr_fd(ft_substr(lst->str, 0, 2), 1);
			ft_putstr_fd(ft_substr(lst->f, 0, lst->prec - lst->s_len + 2), 1);
		}
		else if (lst->width > lst->s_len)
			ft_putstr_fd(ft_substr(lst->spaces, 0, lst->width - lst->s_len), 1);
		ft_putstr_fd(ft_substr(lst->str, 2, ft_strlen(lst->str)), 1);
	}
	else
	{
		if (lst->zero)
			if (lst->width > lst->s_len)
				ft_putstr_fd(ft_substr(lst->f, 0, lst->width - lst->s_len), 1);
		if (!lst->zero)
			if (lst->width > lst->s_len)
				ft_putstr_fd(ft_substr(lst->spaces, 0, \
				lst->width - lst->s_len), 1);
		ft_putstr_fd(lst->str, 1);
	}
	return (ft_max(ft_max(lst->prec + 2, lst->s_len), lst->width));
}

static	int	print_str_just(t_flags *lst)
{
	if (lst->prec >= 0)
	{
		ft_putstr_fd(ft_substr(lst->str, 0, lst->prec), 1);
		if (lst->width > ft_min(lst->prec, lst->s_len))
			ft_putstr_fd(ft_substr(lst->spaces, 0, \
			lst->width - ft_min(lst->prec, lst->s_len)), 1);
	}
	else
	{
		ft_putstr_fd(lst->str, 1);
		if (lst->width > lst->s_len)
			ft_putstr_fd(ft_substr(lst->spaces, 0, \
			lst->width - lst->s_len), 1);
	}
	if (lst->prec >= 0)
		return (ft_max(ft_min(lst->prec, lst->s_len), lst->width));
	else
		return (ft_max(lst->s_len, lst->width));
}

static	int	print_str_not_just(t_flags *lst)
{
	if (lst->prec >= 0)
	{
		if (lst->width > ft_min(lst->prec, lst->s_len))
			ft_putstr_fd(ft_substr(lst->spaces, 0, \
				lst->width - ft_min(lst->prec, lst->s_len)), 1);
		ft_putstr_fd(ft_substr(lst->str, 0, lst->prec), 1);
	}
	else
	{
		if (lst->width > lst->s_len)
		{
			if (!lst->zero)
				ft_putstr_fd(ft_substr(lst->spaces, 0, \
				lst->width - lst->s_len), 1);
			else
				ft_putstr_fd(ft_substr(lst->f, 0, lst->width - lst->s_len), 1);
		}
		ft_putstr_fd(lst->str, 1);
	}
	if (lst->prec >= 0)
		return (ft_max(ft_min(lst->prec, lst->s_len), lst->width));
	else
		return (ft_max(lst->s_len, lst->width));
}

int			ft_printf_print_p_str(t_flags *lst)
{
	int i;

	i = 0;
	if (lst->c == 'p')
	{
		if (lst->just)
			i = print_p_just(lst);
		else
			i = print_p_not_just(lst);
	}
	else if (lst->c == 's')
	{
		if (lst->just)
			i = print_str_just(lst);
		else
			i = print_str_not_just(lst);
	}
	return (i);
}
