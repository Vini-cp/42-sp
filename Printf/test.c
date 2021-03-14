#include <stdio.h>
#include "include/libftprintf.h"

int main()
{
	// char *s_hidden = "hi low\0don't print me lol\0";
	// printf("|%30.20s|\n", "Oi seu vinao, tudo certo?");
	// printf("%d\n", printf("%2.9p\n", 1234));
	// ft_printf("%d\n", ft_printf("%2.9p\n", 1234));
	printf("%d\n", printf("|%10.5d|\n", -123));
	ft_printf("%d\n", ft_printf("|%10d|\n", -123));
	printf("%c\n", 0);
	ft_printf("%c\n", 0);
	printf("%d\n", printf("ABC%"));
	printf("%d\n", printf("%x\n", 0x1234abcdfu));
	printf("%d\n", ft_printf("%x\n", 0x1234abcdfu));
	printf("%d\n", ft_printf("%p\n", 1234));
	// 0 -> 9
	// abcdef
	// 5299
	// char c = 'a';
	// ft_printf("%i\n", c);
	// char *s = NULL;
	// ft_atoi(s);
	// 1) -
	// 2) NUM => (0)NUM / *
	// 3) .
	// 4) NUM / *

	// IGNORAR FLAG 0


	// ft_printf("%05%");
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


// PRECISÃO tem preferência no justify
// PRECISÃO em string é diferente do resto