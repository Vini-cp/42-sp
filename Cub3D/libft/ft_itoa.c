#include "../include/libft.h"

char	*ft_itoa(int num)
{
	int		i;
	int		is_negative;
	char	*str;

	if (num == 0)
		return (str = ft_strdup("0\0"));
	else if (num == -2147483648)
		return (str = ft_strdup("-2147483648\0"));
	i = 0;
	str = (char *)malloc(12 * sizeof(char));
	if (ft_isnegative(num))
		num *= -1;
	while (num != 0)
	{
		str[i++] = num % 10 + '0';
		num = num / 10;
	}
	if (ft_isnegative(num))
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
