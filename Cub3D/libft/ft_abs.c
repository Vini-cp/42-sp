#include "../include/libft.h"

int	ft_abs(int a, int b)
{
	if (a >= b)
		return (a - b);
	else
		return (b - a);
}
