#include "../include/libft.h"

void	ft_printf_empty_zeros(t_flags ***lst)
{
	char	*s;
	char	*t;
	int		i;
	int		size;

	(**lst)->just = ((**lst)->width < 0) ? 1 : (**lst)->just;
	(**lst)->width *= ((**lst)->width < 0) ? -1 : 1;
	size = ((**lst)->width >= (**lst)->prec) ? (**lst)->width : (**lst)->prec;
	s = (char *)malloc((size + 1) * sizeof(char));
	t = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	while (i < size)
	{
		s[i] = '0';
		t[i] = ' ';
		i++;
	}
	s[i] = '\0';
	t[i] = '\0';
	(**lst)->f = ft_strdup(s);
	(**lst)->spaces = ft_strdup(t);
}
