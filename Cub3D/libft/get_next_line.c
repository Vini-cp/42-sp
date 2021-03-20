/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:38:33 by vcordeir          #+#    #+#             */
/*   Updated: 2021/03/19 20:43:05 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		get_next_line(int fd, char **line)
{
	int				out;
	char			s[BUFFER_SIZE + (out = 1)];
	char			*tmp;
	static	char	*t;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1 * ft_memdel((void **)&t));
	t == NULL ? t = ft_calloc(1, sizeof(char)) : NULL;
	while (!ft_strchr(t, '\n') && (out = read(fd, s, BUFFER_SIZE)) > 0)
	{
		s[out] = '\0';
		tmp = ft_strjoin(t, s);
		ft_memdel((void **)&t);
		t = tmp;
	} 
	if (out == 0)
		*line = ft_strdup(t);
	else if (out > 0)
		*line = ft_substr(t, 0, (ft_strchr(t, '\n') - t));
	else
		return (-1);
	tmp = ft_strdup(t + (ft_strlen(*line) + ((out > 0) ? +1 : +0)));
	ft_memdel((void **)&t);
	t = tmp;
	return (out == 0 ? 0 * ft_memdel((void **)&t) : 1);
}
