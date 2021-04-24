#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (*big && little_len <= len)
	{
		if (ft_strncmp(big++, little, little_len) == 0)
			return ((char *)(big - 1));
		len--;
	}
	return (NULL);
}
