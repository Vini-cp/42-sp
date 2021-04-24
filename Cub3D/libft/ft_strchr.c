#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c1;

	c1 = ' ';
	while (c1 != '\0')
	{
		c1 = (unsigned char)*s++;
		if (c1 == c)
			return ((char *)(s - 1));
	}
	return (NULL);
}
