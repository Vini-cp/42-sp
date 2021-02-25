/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:23:11 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/24 23:05:50 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (len)
		str[i - start] = '\0';
	return (str);
}
