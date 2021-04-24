#include "../include/libft.h"

void	ft_printf_get_flag(char *s, va_list args, t_flags ***lst)
{
	int i;

	i = 0;
	while (s[i])
	{
		(**lst)->just = (s[i] == '-') ? 1 : (**lst)->just;
		(**lst)->prec = (s[i] == '.') ? 0 : (**lst)->prec;
		if (s[i] == '*' && (**lst)->prec >= 0)
			(**lst)->prec = va_arg(args, int);
		else if (s[i] == '*' && (**lst)->prec < 0)
			(**lst)->width = va_arg(args, int);
		if (ft_isdigit(*(s + i)))
		{
			(**lst)->zero = (s[i] == '0' && (**lst)->prec < 0) ? \
			1 : (**lst)->zero;
			if ((**lst)->prec >= 0)
				(**lst)->prec = ft_atoi((s + i));
			else
				(**lst)->width = ft_atoi((s + i));
			while (ft_isdigit(s[i]))
				i++;
			i--;
		}
		i++;
	}
}
