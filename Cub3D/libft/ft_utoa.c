#include "../include/libft.h"

char	*ft_utoa(size_t num, int base, int capitalize)
{
	int		i;
	size_t	rem;
	char	*s;
	char	c;

	if (num == 0)
		return (s = ft_strdup("0\0"));
	c = 'a';
	if (capitalize)
		c = ft_toupper(c);
	i = 0;
	s = (char *)malloc(9 * sizeof(char));
	while (num != 0)
	{
		rem = num % base;
		if (rem > 9)
			(rem - 10) + c;
		else
			s[i++] = rem + '0';
		num = num / base;
	}
	s[i] = '\0';
	ft_strrev(s);
	return (s);
}
