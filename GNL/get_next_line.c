/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:38:33 by vcordeir          #+#    #+#             */
/*   Updated: 2021/02/24 23:04:24 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			*s;
	char			*tmp;
	static	char	*t;
	size_t			size;
	int				out;

	out = 1;
	s = (char *)malloc(BUFFER_SIZE * sizeof(char));
	while (out > 0)
	{
		out = read(fd, s, BUFFER_SIZE);
		if (!t)
			t = ft_strdup(s);
		else
			t = ft_strjoin(t, ft_substr(s, 0, out));
		tmp = ft_strchr(t, '\n');
		if (tmp)
		{
			size = ft_strlen(t) - ft_strlen(tmp) + 1;
			*line = (char *)malloc(size * sizeof(char));
			ft_strlcpy(*line, t, size);
			t = ft_strdup(tmp + 1);
			return (1);
		}
		if (out == 0)
		{
			size = ft_strlen(t) + 1;
			*line = (char *)malloc(size * sizeof(char));
			ft_strlcpy(*line, t, size);
			return (0);
		}
	}
	return (out);
}
