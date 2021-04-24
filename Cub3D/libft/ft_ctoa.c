#include "../include/libft.h"

char	*ft_ctoa(char c)
{
	char	*s;

	s = (char *)malloc(2 * sizeof(char));
	s[0] = c;
	s[1] = '\0';
	return (s);
}
