/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 22:16:19 by vcordeir          #+#    #+#             */
/*   Updated: 2021/04/02 22:40:31 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int		read_map_file(int size, char *file)
{
	int		fd;
	int		out;
	int		nb_of_lines;
	char	*s;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (FALSE);
	str = malloc((size - 8 + 1) * sizeof(char *));
	out = 1;
	nb_of_lines = 0;
	while (out > 0)
	{
		out = get_next_line(fd, &s);
		if (s[0])
		{
			if (nb_of_lines >= 8)
				str[nb_of_lines - 8] = ft_strdup(s);
			nb_of_lines++;
		}
	}
	str[nb_of_lines - 8] = NULL;
	// printf("TESTANDO ...\n");
	// while (*str)
		//printf("%s\n", *str++);
	return (TRUE);
}
