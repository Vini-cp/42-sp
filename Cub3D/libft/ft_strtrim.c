#include "../include/libft.h"

static	int	is_set_char(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static	int	get_first_position(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (is_set_char(str[i], set))
		i++;
	return (i);
}

static	int	get_last_position(char const *str, char const *set)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (is_set_char(str[i], set))
		i--;
	return (++i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;
	int		start;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = get_first_position(s1, set);
	len = get_last_position(s1, set) - start;
	if (len < 0)
	{
		str = ft_calloc(1, sizeof(char));
		return (str);
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
