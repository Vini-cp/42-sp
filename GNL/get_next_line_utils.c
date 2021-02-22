/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:23:11 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/21 23:47:23 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		get_end_line (char *s)
{
	int i;

	i = 0;
	while(*s)
	{
		if (*s++ == '\n')
			return (i);
		i++;	
	}
	return (0);
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	i = 0;
	while (dst[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (i + j < size - 1 && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	return (i + j);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *p;

	p = s;
	while (n--)
		*p++ = c;
	return (s);
}
// int main ()
// {
// 	char *s;
// 	int d = 0;
// 	s = "Oi, meu nome\né Goku!";
// 	d = get_new_line (s);
// 	if (d)
// 		printf("TRUE: %d\n", d);
// 	else
// 		printf("FALSE\n");
// 	printf("%s\n", s);
// }