/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:31:58 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/06 14:52:33 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, const char *src);

char 	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;

	len = 0;
	while (s[len] != '\0')
		len++;
	dest = malloc(sizeof(*dest) * (len + 1));
	if (!(dest = malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	ft_strcpy(dest, s);
	return (dest);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
