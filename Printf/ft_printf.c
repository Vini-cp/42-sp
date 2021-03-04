/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 23:13:06 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/04 11:09:12 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *fmt, ...)
{
    va_list args;
    int d;
    char c, *s;

   va_start(args, fmt);
    while (*fmt)
        switch (*fmt++) {
        case 's':              /* string */
            s = va_arg(args, char *);
            printf("string: %s\n", s);
            break;
        case 'd':              /* int */
            d = va_arg(args, int);
            printf("int: %d\n", d);
            break;
        case 'c':              /* char */
            /* need a cast here since va_arg only
               takes fully promoted types */
            c = (char) va_arg(args, int);
            printf("char: %c\n", c);
            break;
        }
    va_end(args);
	return (0);
}

int main()
{
	char s[] = "Oi, meu nome é goku";
	char c = 'A';
	int d = 1234;
	char t[] = "Oi, tudo bom?";
	ft_printf("%s %c %s %d", s, c, t, d);
}