#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*cdst;
	const char	*csrc;

	cdst = dest;
	csrc = src;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		while (n--)
			*cdst++ = *csrc++;
	else
	{
		csrc = csrc + (n - 1);
		cdst = cdst + (n - 1);
		while (n--)
			*cdst-- = *csrc--;
	}
	return (dest);
}
