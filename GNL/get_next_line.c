/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:38:33 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/02 03:16:56 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <stdio.h>

void		*ft_memset(void *s, int c, size_t n)
{
	unsigned char *p;

	p = s;
	while (n--)
		*p++ = c;
	return (s);
}

char		*new_array(size_t size)
{
	void	*ptr;

	if(!(ptr = malloc((size + 1) * sizeof(char))))
		return (NULL);
	ptr = ft_memset(ptr, 0, size);
	return (ptr);
}

int			del(void **ptr)
{
	if (*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

int		get_next_line(int fd, char **line)
{
	int				out;
	char			s[BUFFER_SIZE + 1];
	char			*tmp;
	static	char	*t;
	
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1 * del((void **)&t));
	t == NULL ? t = new_array(0) : NULL;
	while (!ft_strchr(t, '\n') && (out = read(fd, s, BUFFER_SIZE)) > 0)
	{
		s[out] = '\0';
		tmp = ft_strjoin(t, s);
		del((void **)&t);
		t = tmp;
	}
	if (out == 0)
		*line = ft_strdup(t);
	else if (out > 0)
		*line = ft_substr(t, 0, (ft_strchr(t, '\n') - t));
	else
		return (-1);
	tmp = ft_strdup(t + (ft_strlen(*line) + ((out > 0) ? +1 : +0)));
	del((void **)&t);
	t = tmp;
	return (out == 0 ? 0 * del((void **)&t) : 1);
}

// int main ()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	int out = 1;
// 	char *line = NULL;
// 	while (out)
// 	{
// 		out = get_next_line(fd, &line);
// 		printf("%s.\n", line);
// 	}
// 	free(line);
// }