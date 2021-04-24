#include "../include/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*csrc;
	char	*cdest;
	size_t	i;

	csrc = (char *)src;
	cdest = (char *)dest;
	i = n;
	while (n--)
	{
		if ((unsigned char)*csrc == (unsigned char)c)
		{
			i -= n;
			*cdest++ = *csrc;
			return (dest + i);
		}
		*cdest++ = *csrc++;
	}
	return (NULL);
}
