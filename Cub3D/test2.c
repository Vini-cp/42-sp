#include "test.h"


static	int		nb_of_strs(char const *s, char c)
{
	int nb;
	int bool_check;

	nb = 0;
	bool_check = 1;
	while (*s != '\0')
	{
		if (*s == c)
			bool_check = 1;
		else if (*s != c && bool_check)
		{
			nb++;
			bool_check = 0;
		}
		s++;
	}
	return (nb);
}

static	char	*string(const char *s, int init, int end)
{
	char	*str;

	str = (char*)malloc((end - init + 1) * sizeof(char));
	ft_strlcpy(str, (s + init), (end - init + 1));
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	int		start;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = -1;
	j = 0;
	start = -1;
	strs = malloc((nb_of_strs(s, c) + 1) * sizeof(char *));
	if (strs == 0)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			strs[j++] = string(s, start, i);
			start = -1;
		}
	}
	strs[j] = NULL;
	return (strs);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char c1;
	unsigned char c2;

	if (n == 0)
		return (0);
	n--;
	while (n--)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 == '\0' || c1 != c2)
			return (c1 - c2);
	}
	c1 = (unsigned char)*s1++;
	c2 = (unsigned char)*s2++;
	return (c1 - c2);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	if (size == 0)
		return (ft_strlen(src));
	if (!dst && !src)
		return (0);
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	j = 0;
	while (src[j] != '\0')
	{
		j++;
	}
	return (j);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;

	len = ft_strlen(s);
	if (!(dest = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(dest, s, (len + 1));
	return (dest);
}

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
	if (!(strjoin = (char*)malloc((len_s1 + len_s2 + 1) * sizeof(char))))
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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *p;

	p = s;
	while (n--)
		*p++ = c;
	return (s);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void *p;

	if (!(p = malloc(nelem * elsize)))
		return (NULL);
	p = ft_memset(p, 0, nelem * elsize);
	return (p);
}

int		ft_memdel(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char c1;

	c1 = ' ';
	while (c1 != '\0')
	{
		c1 = (unsigned char)*s++;
		if (c1 == c)
			return (char *)(s - 1);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		if (!(str = (char*)malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = start;
	while (s[i] != '\0' && len--)
	{
		str[i - start] = s[i];
		i++;
	}
	str[i - start] = '\0';
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int				out;
	char			s[BUFFER_SIZE + (out = 1)];
	char			*tmp;
	static	char	*t;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1 * ft_memdel((void **)&t));
	t == NULL ? t = ft_calloc(1, sizeof(char)) : NULL;
	while (!ft_strchr(t, '\n') && (out = read(fd, s, BUFFER_SIZE)) > 0)
	{
		s[out] = '\0';
		tmp = ft_strjoin(t, s);
		ft_memdel((void **)&t);
		t = tmp;
	} 
	if (out == 0)
		*line = ft_strdup(t);
	else if (out > 0)
		*line = ft_substr(t, 0, (ft_strchr(t, '\n') - t));
	else
		return (-1);
	tmp = ft_strdup(t + (ft_strlen(*line) + ((out > 0) ? +1 : +0)));
	ft_memdel((void **)&t);
	t = tmp;
	return (out == 0 ? 0 * ft_memdel((void **)&t) : 1);
}
