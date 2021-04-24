#include "../include/libft.h"

char	*ft_ptoa(uintptr_t num, int prec)
{
	int			i;
	uintptr_t	rem;
	char		*s;

	if (num == 0 && prec != 0)
		return (s = ft_strdup("0x0\0"));
	else if (num == 0 && prec == 0)
		return (s = ft_strdup("0x\0"));
	i = 0;
	s = (char *)malloc(19 * sizeof(char));
	while (num != 0)
	{
		rem = num % 16;
		if (rem > 9)
			s[i++] = (rem - 10) + 'a';
		else
			s[i++] = rem + '0';
		num = num / 16;
	}
	s[i++] = 'x';
	s[i++] = '0';
	s[i] = '\0';
	ft_strrev(s);
	return (s);
}
