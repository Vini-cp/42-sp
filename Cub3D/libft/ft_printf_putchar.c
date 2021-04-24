#include "../include/libft.h"

int	ft_printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
