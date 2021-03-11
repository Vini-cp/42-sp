/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 23:13:06 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/11 19:30:46 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

// flags(int size, int zeros)
// size: int
// 		array size
// zeros: bool
// 		1: complete with zero
// 		0: complete with spaces

char	*flag(int size, int zeros)
{
	char		c;
	char		*s;
	int			i;
	
	c = (zeros)? '0': ' ';
	s = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	while(i < size)
		s[i++] = c;
	s[i] = '\0';
	return (s);
}

int		check_flag(const char *fmt, va_list args, to_print **lst)
{
	if (ft_isdigit(*fmt) && *fmt > '0')
	{
		(*lst)->flag = flag((*fmt - '0'), 0);
		return (1);
	}
	else if (*fmt == '*')
	{
		(*lst)->flag = flag(va_arg(args, int), 0);
		return (1);
	}
	else if (*fmt == '.' && *(fmt + 1) == '*')
	{
		fmt += 1;
		(*lst)->flag = flag(va_arg(args, int), 1);
		return (2);
	}
	else if ((*fmt == '.' || *fmt == '0') && ft_isdigit(*(fmt + 1)))
	{
		(*lst)->flag = flag((*(fmt + 1) - '0'), 1);
		return (2);
	}
	return (0);
}

to_print	*lstnew()
{
	to_print *lst;
	lst = (to_print *)malloc(sizeof(to_print));
	lst->flag = NULL;
	lst->string = NULL;
	return (lst);
}

int	ft_aux(const char *f, va_list args, to_print *lst, int just)
{
	if (*f == 'd' || *f == 'i')				/* int */
		lst->string = ft_itoa(va_arg(args, int));
	else if (*f == 'c')						/* char */
		lst->string = ft_ctoa((char) va_arg(args, int));
	else if (*f == 's')						/* string */
		lst->string = va_arg(args, char *);
	else if (*f == 'u')						/* unsigned int */
		lst->string = ft_utoa(va_arg(args, unsigned int), 10, 0);
	else if (*f == 'x')						/* hex lower */
		lst->string = ft_utoa(va_arg(args, unsigned int), 16, 0);
	else if (*f == 'X')						/* hex lower */
		lst->string = ft_utoa(va_arg(args, unsigned int), 16, 1);
	else if (*f == 'p')						/* pointer */
		lst->string = ft_ptoa(va_arg(args, uintptr_t));
	lst->flag_len = (lst->flag)? ft_strlen(lst->flag) : 0;
	lst->str_len = ft_strlen(lst->string);
	if (!just)
		if (lst->flag && (lst->flag_len > lst->str_len))
			ft_putstr_fd(ft_substr(lst->flag, 0, lst->flag_len - lst->str_len), 1);
	ft_putstr_fd(lst->string, 1);
	if (just && lst->flag[0] == ' ')
		if (lst->flag && (lst->flag_len > lst->str_len))
			ft_putstr_fd(ft_substr(lst->flag, 0, lst->flag_len - lst->str_len), 1);
	return ((lst->flag && (lst->flag_len > lst->str_len) && (!just  || (just \
	&& lst->flag[0] == ' ')))? lst->flag_len : lst->str_len);
}

int		ft_printf(const char *fmt, ...)
{
	va_list args;
	to_print *node;
	int i;
	int just;

	i = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		just = 0;
		node = lstnew();
		if (*fmt == '%')
		{
			fmt += 1;
			if (*fmt == '-')
			{
				just = 1;
				fmt += 1;
			}
			if (*fmt == '%')
				i += ft_printf_putchar(*fmt);
			else if (ft_isdigit(*fmt) || *fmt == '*' || *fmt == '.')
			{
				fmt += check_flag(fmt, args, &node);
				i += ft_aux(fmt, args, node, just);
			}
			else
				i += ft_aux(fmt, args, node, just);
			fmt += 1;
		}
		else
			i += ft_printf_putchar(*(fmt++));
	}
	va_end(args);
	return (i);
}

int main()
{
	int d = 10; // 7
	// text= dado 4 + 1 = 5
	int i = 48523756; // 8
	// text= inteligente 11 + 1 = 12
	char c = 'A'; // 1 + 1 = 2
	char s[11] = "AbCdEfGhIj\0"; //12 + 1 = 13
	size_t u = 4294967295; // 15 + 1 + 1= 16
	size_t x = 4294967295; // 8 + 1 = 9
	size_t X = 4294967295; // 8 + 1 = 9
	int *p = &d;// 20 + 1 = 21
	//103
	printf("%d\n", ft_printf("%07ddado\n%iinteligente\n%c\n%.*s\n%-*u.\n%x\n%X\n%*p\n", d, i, c, 12, s, 15, u, x, X, 20, p));
}