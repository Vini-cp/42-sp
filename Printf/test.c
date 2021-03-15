#include <stdio.h>
#include "include/libftprintf.h"

int main()
{
	// printf("%d\n", printf("|%131p|\n",(void*)14631880201060661778lu));
	printf("%d\n", ft_printf("|%131p|\n",(void*)14631880201060661778lu));
}

// 0xcb0ee185144aba12