#include <stdio.h>
#include "include/libftprintf.h"

char* itoa(int num) 
{ 
    int i; 
    int isNegative;
	int rem;
	char *str;

    if (num == 0)
		return ("0\0");
	if (num == -2147483648)
		return ("-2147483648\0");
	i = 0;
	str = (char *)malloc(12 * sizeof(char));
	isNegative = (num < 0)? 1 : 0;
	num *= (isNegative)? -1 : 1;
    while (num != 0)
    {
        rem = num % base;
        str[i++] = (rem > 9)? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }
    if (isNegative)
        str[i++] = '-';
    str[i] = '\0';
    ft_strrev(str);
    return str;
}










int main ()
{
	printf("%5d.\n", 10);
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
