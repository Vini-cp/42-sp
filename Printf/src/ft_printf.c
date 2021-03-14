/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 23:13:06 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/14 18:37:06 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

static	char		*create_flag_array(const char *fmt)
{
	int		i;
	char	*s;

	i = 0;
	while (ft_printf_isflag(fmt[i]) || ft_isdigit(fmt[i]))
		i++;
	s = ft_substr(fmt, 0, i);
	return (s);
}

static	void		to_string(const char *f, va_list args, to_print **lst)
{
	(*lst)->c = ' ';
	if (*f == 'd' || *f == 'i')
		(*lst)->str = ft_itoa(va_arg(args, int));
	else if (*f == 'c')
		(*lst)->str = ft_ctoa((char)va_arg(args, int));
	else if (*f == 's')
	{
		(*lst)->str = va_arg(args, char *);
		(*lst)->c = 's';
		(*lst)->str = ((*lst)->str) ? (*lst)->str : "(null)\0";
	}
	else if (*f == 'u')
		(*lst)->str = ft_utoa(va_arg(args, unsigned int), 10, 0);
	else if (*f == 'x')
		(*lst)->str = ft_utoa(va_arg(args, unsigned int), 16, 0);
	else if (*f == 'X')
		(*lst)->str = ft_utoa(va_arg(args, unsigned int), 16, 1);
	else if (*f == 'p')
	{
		(*lst)->str = ft_ptoa(va_arg(args, uintptr_t), (*lst)->prec);
		(*lst)->c = 'p';
	}
	else if (*f == '%')
		(*lst)->str = ft_ctoa(*f);
	(*lst)->s_len = ((*lst)->str) ? ft_strlen((*lst)->str) : 0;
}

static	to_print	*lstnew(void)
{
	to_print *lst;

	lst = (to_print *)malloc(sizeof(to_print));
	lst->f = NULL;
	lst->str = NULL;
	lst->spaces = NULL;
	lst->just = 0;
	lst->prec = -1;
	lst->width = -1;
	lst->zero = 0;
	return (lst);
}

int					ft_printf(const char *fmt, ...)
{
	va_list		args;
	to_print	*node;
	int			i;

	i = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		node = lstnew();
		if (*fmt == '%')
		{
			if (!*(fmt + 1))
				return (i);
			fmt += 1;
			if (*fmt == '%')
				i += ft_printf_putchar(*fmt);
			else if (ft_isdigit(*fmt) || ft_printf_isflag(*fmt))
			{
				ft_printf_get_flag(create_flag_array(fmt), args, &node);
				ft_printf_empty_zeros(&node);
				fmt += ft_strlen(create_flag_array(fmt));
				if (!*fmt)
					return (i);
				to_string(fmt, args, &node);
				i += (node->c == ' ') ? ft_printf_print(node) : \
				ft_printf_print_p_str(node);
			}
			else
			{
				to_string(fmt, args, &node);
				i += (node->c == ' ') ? ft_printf_print(node) : \
				ft_printf_print_p_str(node);
			}
			fmt += 1;
		}
		else
			i += ft_printf_putchar(*(fmt++));
	}
	va_end(args);
	return (i);
}
