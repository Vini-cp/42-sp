#include <stdio.h>
#include "include/libftprintf.h"

char	*ft_ptoa(uintptr_t num)
{ 
    int         i;
	uintptr_t   rem;
	char        *s;

    if (num == 0)
		return (s = ft_strdup("0\0"));
	i = 0;
	s = (char *)malloc(9 * sizeof(char));
    while (num != 0)
    {
        rem = num % 16;
        s[i++] = (rem > 9)? (rem - 10) + 'a' : rem + '0';
        num = num / 16;
    }
    s[i++] = 'x';
    s[i++] = '0';
    s[i] = '\0';
    ft_strrev(s);
    return (s);
}

int main()
{
	char *s;
	int d = 10;
	s = ft_ptoa((uintptr_t)&d);
	printf("%s\n", s);
	printf("%p\n", &d);
	// s = ft_utoa(112450, 16, 0);
	// printf("%s\n", s);
	// printf("%x\n", 112450);
}


// int main ()
// {
// 	printf("%5d.\n", 10);
// 	printf("%*d\n", 5, 10);
// 	printf("%-5d.\n", 10);
// 	printf("%.5d\n", 10);
// 	printf("%.*d\n", 5, 10);
// 	printf("%05d\n", 10);
// 	printf("%00d\n", 10);
// 	printf("%.0d\n", 10);
// }

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
