#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;

	str = (char *)s;
	len = ft_strlen(s);
	str += (len);
	while (len-- >= 0)
	{
		if (*str-- == c)
			return ((char *)(str + 1));
	}
	return (NULL);
}
