#include "../include/libft.h"

void	ft_strrev(char *str)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		i++;
	}
}
