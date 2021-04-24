#include "../include/libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*p;

	p = malloc(nelem * elsize);
	if (!p)
		return (NULL);
	p = ft_memset(p, 0, nelem * elsize);
	return (p);
}
