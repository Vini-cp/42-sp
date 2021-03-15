/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 23:13:06 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/15 20:06:29 by vcordeir         ###   ########.fr       */
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

static	void		to_string(const char *f, va_list args, t_flags **lst)
{
	(*lst)->c = ' ';
	if (*f == 'd' || *f == 'i')
		(*lst)->str = ft_itoa(va_arg(args, int));
	else if (*f == 'c')
		(*lst)->print_c = (char)va_arg(args, int);
	else if (*f == 's')
		(*lst)->str = va_arg(args, char *);
	else if (*f == 'u')
		(*lst)->str = ft_utoa(va_arg(args, unsigned int), 10, 0);
	else if (*f == 'x')
		(*lst)->str = ft_utoa(va_arg(args, unsigned int), 16, 0);
	else if (*f == 'X')
		(*lst)->str = ft_utoa(va_arg(args, unsigned int), 16, 1);
	else if (*f == 'p')
		(*lst)->str = ft_ptoa(va_arg(args, uintptr_t), (*lst)->prec);
	else if (*f == '%')
		(*lst)->print_c = (*f);
	(*lst)->c = (*f == 's') ? 's' : (*lst)->c;
	(*lst)->c = (*f == 'p') ? 'p' : (*lst)->c;
	(*lst)->c = (*f == 'c' || *f == '%') ? 'c' : (*lst)->c;
	(*lst)->c = (*f == 'u') ? 'u' : (*lst)->c;
	(*lst)->str = ((*lst)->str) ? (*lst)->str : "(null)\0";
	(*lst)->s_len = ((*lst)->str) ? ft_strlen((*lst)->str) : 0;
}

static	t_flags	*lstnew(void)
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

int					ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_flags		*node;
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
				i += (node->c == ' ' || node->c == 'c' || node->c == 'u') ? ft_printf_print(node) : \
				ft_printf_print_p_str(node);
			}
			else
			{
				to_string(fmt, args, &node);
				i += (node->c == ' ' || node->c == 'c' || node->c == 'u') ? ft_printf_print(node) : \
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
