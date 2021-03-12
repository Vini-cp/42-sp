#include <stdio.h>
#include "include/libftprintf.h"

int main()
{
	// printf("%-05%.\n");
	ft_printf("%-05%.\n");
	// printf(" .%-15d. \n", 7);
	// printf("%-.5%.\n");
	// ft_printf("%");
	// printf("%5");
	// printf("%05");
	// printf("%-05");
	// printf("%-5");
	// printf("%p\n", &d);
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
// }

// Left or Rigth			
// 	- num > 0			(printa num espaços)						OK
// 	- ast				(busca num e printa num espaços)			OK
// 	- ponto e ast		(busca num e printa num zeros)				OK		
// 	- ponto e num		(printa num zeros)							OK
// 	- zero e num		(printa num zeros)							




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
