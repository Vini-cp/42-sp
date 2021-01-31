/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:33:55 by vcordeir          #+#    #+#             */
/*   Updated: 2020/12/04 02:39:13 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *str);
int		len_calc(int size, char **strs, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*strjoin;

	if (size == 0)
	{
		strjoin = (char*)malloc(sizeof(char));
		return (strjoin);
	}
	len = len_calc(size, strs, sep);
	strjoin = (char*)malloc(len);
	i = 0;
	while (i < size)
	{
		ft_strcat(strjoin, strs[i]);
		if (i < (size - 1))
			ft_strcat(strjoin, sep);
		i++;
	}
	return (strjoin);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

int		len_calc(int size, char **strs, char *sep)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		if (i < (size - 1))
			len += ft_strlen(sep);
		i++;
	}
	len++;
	return (len);
}
