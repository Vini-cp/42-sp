/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:38:33 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/22 00:17:38 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

// usar a variável estática "t" para sempre receber o conteúdo de "s"
// caso o conteúdo de "s" tenha um NEW LINE + algum outro caractere
// será necessário passar todo o conteúdo excedente para t depois
// que t for passado para line

int		get_next_line(int fd, char **line)
{
	char			*s;
	// static	char	*t;
	int				size;
	int				i;
	
	i = 0;
	s = (char*)malloc(BUFFER_SIZE*sizeof(char));
	while (read(fd, s, BUFFER_SIZE) > 0)
	{
		if (!*s)
			return (0);
		size = get_end_line(s);
		if (size)
		{
			if (line)
			{
				*(line + i * BUFFER_SIZE) = (char *)malloc(BUFFER_SIZE*sizeof(char));
				ft_strlcat(*line, s, (i * BUFFER_SIZE + size + 1));
			}
			else
			{
				*line = (char *)malloc(size*sizeof(char));
				ft_strlcat(*line, s, size + 1);
			}
            return (1);
		}
		*(line + i * BUFFER_SIZE) = (char *)malloc(BUFFER_SIZE*sizeof(char));
		ft_strlcat(*line, s, ((i + 1) * BUFFER_SIZE + 1));
		// printf("TESTE: %s\n", s);
		ft_memset(s, 0, BUFFER_SIZE);
		i++;
	}
	return (0);
}

int main ()
{
	int fd;
	int out;
	char * line = NULL;
	
	fd = open("test.txt", O_RDONLY);
	out = 1;
	while (out)
	{
		out = get_next_line(fd, &line);
		printf("%s\n", line);
	}
}