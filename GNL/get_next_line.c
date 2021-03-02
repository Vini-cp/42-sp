/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:38:33 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/02 00:20:36 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static	char	*init_pointer(char *s, char *t, int size)
{
	s[size] = '\0';
	if (!t)
		return(ft_strdup(s));
	else
		return(ft_strjoin(t, ft_substr(s, 0, size + 1)));
}

static	char	*allocate_line(char *t, char *tmp)
{
	size_t	size;
	
	size = ft_strlen(t) - ft_strlen(tmp) + 1;
	return(ft_substr(t, 0, size - 1));
}

int		get_next_line(int fd, char **line)
{
	char			*s;
	char			*tmp;
	static	char	*t;
	int				out;
	
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	s = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));	
	while ((out = read(fd, s, BUFFER_SIZE)) >= 0)
	{
		t = init_pointer(s, t, out);
		if ((tmp = ft_strchr(t, '\n')))
		{
			*line = allocate_line(t, tmp);
			t = ft_strdup(tmp + 1);
			return (1);
		}
		if (out == 0)
		{
			*line = ft_strdup(t);
			return (0);
		}
	}
	return (out);
}

int main ()
{
	int fd = open("test.txt", O_RDONLY);
	int out = 1;
	char *line = NULL;
	while (out)
	{
		out = get_next_line(fd, &line);
		printf("%s.\n", line);
	}
	free(line);
}