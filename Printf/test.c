#include <stdio.h>
#include "include/libftprintf.h"

int main()
{
	// ft_printf("%20.0s", "Hallo heimur")
	// ft_printf("%20.s", "Hallo heimur")
	printf("%d\n", printf("|%20.d|\n", 0));
	printf("%d\n", ft_printf("|%20.d|\n", 0));
	printf("%d\n", printf("|%20.i|\n", 0));
	printf("%d\n", ft_printf("|%20.i|\n", 0));
	printf("%d\n", printf("|%20.u|\n", 0u));
	printf("%d\n", ft_printf("|%20.u|\n", 0u));
	printf("%d\n", printf("|%20.X|\n", 0u));
	printf("%d\n", ft_printf("|%20.X|\n", 0u));
	// ft_printf("%-89c%20p%-33.16X%--11.*s%--25.85u" ,10,(void*)1144206967121894099lu,1538791465u,84,"L;x)-34d4BU9<aJE-\n\r4:[)kMj}Y4",543381790u)
	// ft_printf("%64p%038.87d%23c%--182.49i%--76.110%" ,(void*)10278319775164267212lu,-1550079501,30,-862355787)
	// ft_printf("%29p%0151.162x%---53.46u%-139.26X" ,(void*)17894711340605174765lu,1565093748u,662758369u,3536629372u)
	// ft_printf("%108p%-175.188i" ,(void*)11721873312409420167lu,-653373315)
}