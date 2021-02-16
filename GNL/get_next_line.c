/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:38:33 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/16 00:28:47 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	get_next_line(int fd, char **line)
{
	size_t nbytes;
	ssize_t bytes_read = 1;
	char *s;
	
	nbytes = BUFFER_SIZE;
	s = (char*)malloc(BUFFER_SIZE*sizeof(char));
	*s = ' ';
	while (nbytes-- && *(s - 1) != '\n' && bytes_read == 1)
		bytes_read = read(fd, s++, 1);
	*(s - 1) = '\0';
	*line = s - (BUFFER_SIZE - nbytes - 1);
	**line = ' ';
	if (bytes_read == -1)
		return (-1);
	else if (bytes_read == 0)
		return (0);
	else
		return (1);	
}

void	doprint(int out, char **str, int line)
{
	printf("(LINE %i) [OUT %i] |%s|\n", line, out, *str);
	free(*str);
	*str = NULL;
}

void	testmultiple(int fd, int fd2)
{
	char	*st;
	int		i;
	int		i2;

	st = NULL;
	i = 1;
	i2 = 1;
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	close(fd);
	close(fd2);
}

void	test(int fd)
{
	char	*st;
	int		out;
	int		i;

	st = NULL;
	i = 1;
	out = 1;
	while (out == 1)
	{
		out = get_next_line(fd, &st);
		doprint(out, &st, i++);
	}
	close(fd);
}

int		main()
{
	int		fd;
	// int		fd2;

	
	// test(0);
	// test(1250834982);
	// test(612985234);
	
	fd = open("1.txt", O_RDONLY);
	test(fd);
	
	// fd = open(argv[1], O_RDONLY);
	// fd2 = open(argv[2], O_RDONLY);
	// testmultiple(fd, fd2);
	
	return (0);
}
