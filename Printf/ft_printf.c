/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 23:13:06 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/04 23:10:07 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt += 1;
			if (*fmt == 's')							/* string */
				ft_putstr(va_arg(args, char *));
			else if (*fmt == 'd' || *fmt == 'i')		/* int */
				ft_putnbr(va_arg(args, int));
			else if (*fmt == 'u')						/* unsigned int */
				ft_put_unsignednbr(va_arg(args, unsigned int));
			else if (*fmt == 'x')						/* hex lower */
				ft_puthex(va_arg(args, unsigned int), 1);
			else if (*fmt == 'X')						/* hex lower */
				ft_puthex(va_arg(args, unsigned int), 0);
			else if (*fmt == 'c')						/* char */
				ft_putchar((char) va_arg(args, int));
			else if (*fmt == '%')						/* % */
				ft_putchar(*(fmt));
			else if (*fmt == 'p')						/* pointer */
			{
				ft_putstr("0x");
				ft_putpointer(va_arg(args, uintptr_t));
			}
			fmt += 1;
		}
		else											/* type from user */
			ft_putchar(*(fmt++));
	}
	va_end(args);
	return (0);
}

int main()
{
	// char s[] = "Oi, meu nome é goku";
	// char c = 'A';
	// int d = 1234;
	// int i = 10;
	// unsigned int u = 4294967295;
	// char t[] = "Oi, tudo bom?";
	// ft_printf("PRINTANDO:\n%ssapo\n%ccachorro\n%iinteligente\n%ssabonete\n%ddado\nABC\n", s, c, i, t, d);
	// ft_printf("%u\n", u);

	// char *p;
	// p = "Alou";
	// char c = 'a';
	// int f = 10;
	// printf("%p\n", p);
	// ft_printf("%p\n\n", p);

	// printf("%p\n", &c);
	// ft_printf("%p\n\n", &c);

	// printf("%p\n", &f);
	// ft_printf("%p\n\n", &f);
	
	// // printf("%c\n", (++p)++));
	// // printf("%c\n", (*p++));
	// printf("%c\n", (*p));

	// printf("%x\n", 112450);
	// ft_printf("%x\n", 112450);
	// printf("%X\n", 112450);
	// ft_printf("%X\n", 112450);
	// ft_printf("ABC = ABC %% DEF\n");

	printf("\t%d \n", 10);
	printf(" %-d \n", 10);
    printf("%010d \n", 10);


	printf("%020i        .\n", 10);
}