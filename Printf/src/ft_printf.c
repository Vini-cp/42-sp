/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 23:13:06 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/08 21:22:45 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

int	ft_aux(const char *f, va_list args)
{
	int i;

	i = 0;
	if (*f == 's')							/* string */
		i += ft_putstr(va_arg(args, char *));
	else if (*f == 'd' || *f == 'i')		/* int */
		i += ft_putnbr(va_arg(args, int));
	else if (*f == 'u')						/* unsigned int */
		i += ft_putunbr(va_arg(args, unsigned int));
	else if (*f == 'x')						/* hex lower */
		i += ft_puthex(va_arg(args, unsigned int), 1);
	else if (*f == 'X')						/* hex lower */
		i += ft_puthex(va_arg(args, unsigned int), 0);
	else if (*f == 'c')						/* char */
		i += ft_putchar((char) va_arg(args, int));
	else if (*f == 'p')						/* pointer */
	{
		i += ft_putstr("0x");
		i += ft_putptr(va_arg(args, uintptr_t));
	}
	return (i);
}

int		ft_printf(const char *fmt, ...)
{
	va_list args;
	int i;

	i = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt += 1;
			if (*fmt == '%')
				i += ft_putchar(*fmt);							/* % */
			// else if (ft_isdigit(*fmt) || ft_printf_flags(*fmt))
																/* flags */
			else
				i += ft_aux(fmt, args);							/* see above */
			fmt += 1;
		}
		else
			i += ft_putchar(*(fmt++));							/* letter */
	}
	va_end(args);
	return (i);
}

// int main()
// {
// 	char s[] = "Oi, meu nome é goku";
// 	char c = 'A';
// 	int d = 1234;
// 	int i = 10;
// 	char t[] = "Oi, tudo bom?";
// 	ft_printf("PRINTANDO:\n%ssapo\n%ccachorro\n%iinteligente\n%ssabonete\n%ddado\nABC\n", s, c, i, t, d);
// 	// unsigned int u = 4294967295;
// 	// ft_printf("%u\n", u);

// 	// char *p;
// 	// p = "Alou";
// 	// printf("%d\n", ft_printf("%s\n%d\n%c\n%i\n", p, d, c, i));
// 	// char c = 'a';
// 	// int f = 10;
// 	// printf("%p\n", p);
// 	// ft_printf("%p\n\n", p);

// 	// printf("%p\n", &c);
// 	// ft_printf("%p\n\n", &c);

// 	// printf("%p\n", &f);
// 	// ft_printf("%p\n\n", &f);
	
// 	// // printf("%c\n", (++p)++));
// 	// // printf("%c\n", (*p++));
// 	// printf("%c\n", (*p));

// 	// printf("%x\n", 112450);
// 	// ft_printf("%x\n", 112450);
// 	// printf("%X\n", 112450);
// 	// ft_printf("%X\n", 112450);
// 	// ft_printf("ABC = ABC %% DEF\n");

// 	// printf("\t%d \n", 10);
// 	// printf(" %-d \n", 10);
//     // printf("%010d \n", 10);


// 	// printf("%020i        .\n", 10);
// }