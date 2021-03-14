/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 23:13:06 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/14 01:21:09 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

// flags(int size, int zeros)
// size: int
// 		array size
// zeros: bool
// 		1: complete with zero
// 		0: complete with spaces

int		ft_isflag(int c)
{
	if (c == '*' || c == '.' || c == '-')
		return (1);
	else
		return (0);
}

char	*flag_array(const char *fmt)
{
	int	i;
	char *s;

	i = 0;
	while(ft_isflag(fmt[i]) || ft_isdigit(fmt[i]))
		i++;
	s = ft_substr(fmt, 0, i);
	return (s);
}

void	flag_to_print(char *s, va_list args, to_print **lst)
{
	int i;

	i = 0;
	while (s[i])
	{
		(*lst)->just = (s[i] == '-')? 1 : (*lst)->just;
		(*lst)->prec = (s[i] == '.')? 0 : (*lst)->prec;
		if (s[i] == '*' && (*lst)->prec >= 0)
			(*lst)->prec = va_arg(args, int);
		else if (s[i] == '*' && (*lst)->prec < 0)
			(*lst)->width = va_arg(args, int);
		if (ft_isdigit(*(s + i)))
		{
			(*lst)->zero = (s[i] == '0' && (*lst)->prec < 0)? 1 : (*lst)->zero;
			if ((*lst)->prec >= 0)
				(*lst)->prec = ft_atoi((s + i));
			else
				(*lst)->width = ft_atoi((s + i));
			while (ft_isdigit(s[i]))
				i++;
			i--;
		}
		i++;
	}
}

void	flag(to_print **lst)
{
	char	*s;
	char	*t;
	int		i;
	int		size;
	
	size = ((*lst)->width >= (*lst)->prec)? (*lst)->width : (*lst)->prec;
	s = (char *)malloc((size + 1) * sizeof(char));
	t = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	while(i < size)
	{
		s[i] = '0';
		t[i] = ' ';
		i++;
	}
	s[i] = '\0';
	t[i] = '\0';
	(*lst)->f = s;
	(*lst)->spaces = t;
}

to_print	*lstnew()
{
	to_print *lst;
	lst = (to_print *)malloc(sizeof(to_print));
	lst->f = NULL;
	lst->str = NULL;
	lst->print = NULL;
	lst->spaces = NULL;
	lst->just = 0;
	lst->prec = -1;
	lst->width = -1;
	lst->zero = 0;
	return (lst);
}

void	string(const char *f, va_list args, to_print **lst)
{
	(*lst)->c = ' ';
	if (*f == 'd' || *f == 'i')				/* int */
		(*lst)->str = ft_itoa(va_arg(args, int));
	else if (*f == 'c')						/* char */
		(*lst)->str = ft_ctoa((char) va_arg(args, int));
	else if (*f == 's')						/* string */
	{
		(*lst)->str = va_arg(args, char *);
		(*lst)->c = 's';
		(*lst)->str = ((*lst)->str)? (*lst)->str : "(null)\0";
	}
	else if (*f == 'u')						/* unsigned int */
		(*lst)->str = ft_utoa(va_arg(args, unsigned int), 10, 0);
	else if (*f == 'x')						/* hex lower */
		(*lst)->str = ft_utoa(va_arg(args, unsigned int), 16, 0);
	else if (*f == 'X')						/* hex lower */
		(*lst)->str = ft_utoa(va_arg(args, unsigned int), 16, 1);
	else if (*f == 'p')						/* pointer */
	{
		(*lst)->str = ft_ptoa(va_arg(args, uintptr_t), (*lst)->prec);
		(*lst)->c = 'p';
	}
	else if (*f == '%')
		(*lst)->str = ft_ctoa(*f);
	(*lst)->s_len = ((*lst)->str)? ft_strlen((*lst)->str) : 0;
}



int		ft_printf(const char *fmt, ...)
{
	va_list args;
	to_print *node;
	int i;

	i = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		node = lstnew();
		if (*fmt == '%')
		{
			if (!*(fmt + 1))
				return (0);
			fmt += 1;
			if (*fmt == '%')
				i += ft_printf_putchar(*fmt);
			else if (ft_isdigit(*fmt) || ft_isflag(*fmt))
			{
				flag_to_print(flag_array(fmt), args, &node);
				flag(&node);
				fmt += ft_strlen(flag_array(fmt));
				if (!*fmt)
					return (0);
				string(fmt, args, &node);
				// printf("f: %s\n", node->f);
				// printf("s_len: %d\n", node->s_len);
				// printf("Just: %d\n", node->just);
				// printf("prec: %d\n", node->prec);
				// printf("width: %d\n", node->width);
				// printf("zero: %d\n", node->zero);
				// printf("char: %c\n", node->c);
				i += (node->c == ' ')? ft_printf_print(node) : ft_printf_print_p_str(node);
			}
			else
			{
				string(fmt, args, &node);
				i += (node->c == ' ')? ft_printf_print(node) : ft_printf_print_p_str(node);
			}
			fmt += 1;
		}
		else
			i += ft_printf_putchar(*(fmt++));
	}
	va_end(args);
	return (i);
}

// int main()
// {
// 	int d = 10; // 7
// 	// text= dado 4 + 1 = 5
// 	int i = 48523756; // 8
// 	// text= inteligente 11 + 1 = 12
// 	char c = 'A'; // 1 + 1 = 2
// 	char s[11] = "AbCdEfGhIj\0"; //5 + 1 = 6
// 	size_t u = 4294967295; // 15 + 1 + 1= 17
// 	size_t x = 4294967295; // 8 + 1 = 9
// 	size_t X = 4294967295; // 8 + 1 = 9
// 	int *p = &d;// 20 + 1 = 21
// 	printf("%d\n", ft_printf("%07ddado\n%iinteligente\n%c\n%.*s\n%-*u.\n%x\n%X\n%*p\n", d, i, c, 5, s, 15, u, x, X, 20, p));
// 	// ft_printf("%05d|\n", d);
// }
