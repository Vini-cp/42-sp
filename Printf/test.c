#include <stdio.h>
#include "includes/libftprintf.h"

// char	*ft_putnbr(int n)
// {
// 	int i;
// 	char *s;

// 	s = 
// 	i = 0;
// 	if (n == -2147483648)
// 		i += ft_putstr("-2147483648");
// 	else
// 	{
// 		if (n < 0)
// 		{
// 			i += ft_putchar('-');
// 			n = n * (-1);
// 		}
// 		if (n > 9)
// 		{
// 			i += ft_putnbr((n / 10));
// 			i += ft_putnbr((n % 10));
// 		}
// 		else
// 			i += ft_putchar((n + '0'));
// 	}
// 	return (i);
// }











int main ()
{
	ft_printf("%d\n", 10);
	printf("%5d\n", 10);
	printf("%*d\n", 5, 10);
	printf("%-5d.\n", 10);
	printf("%.5d\n", 10);
	printf("%.*d\n", 5, 10);
	printf("%05d\n", 10);
	printf("%00d\n", 10);
	printf("%.0d\n", 10);
}

// 1) Testar se c == '-'
// 	- Print no número e se sobrar espaço, completar com ' ';
// 2) Testar se c é um dígito
// 	- Se c == 0
// 		- Tester se c + 1 != dígito
// 			- /* Preencher com espaços */
// 		- Tester se c + 1 == dígito
// 			- /* Preencher com zeros */
// 	- Se c > 0
// 		- /* Preencher com espaços */
// 3) Testar se c == '*'
// 	- Buscar nos args um int;
// 	- /* Preencher com espaços */
// 4) Testar se c == '.'
// 	- 

// .
// 0
// -
// "width"

// - : Left-justify within the given field width;
// . : precision
// 	.(number) : specifies the minimum number of digits to be written
// 	.* : The precision is not specified in the format string, 
// 		 but as an additional integer value argument preceding 
// 		 the argument that has to be formatted.
// 0 : Left-pads the number with zeroes (0) instead of spaces when padding is specified
// "width" : 
// 			(number) : Minimum number of characters to be printed.
// 			* : The width is not specified in the format string, 
// 				but as an additional integer value argument preceding 
// 				the argument that has to be formatted.