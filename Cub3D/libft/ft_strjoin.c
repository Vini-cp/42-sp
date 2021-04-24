#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strjoin = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (i < len_s2 + len_s1)
	{
		strjoin[i] = s2[i - len_s1];
		i++;
	}
	strjoin[i] = '\0';
	return (strjoin);
}
