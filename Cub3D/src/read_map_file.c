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

static	void	print_test(char *s)
{
	char **str;

	str = ft_split(s, ' ');
	if (!ft_strncmp(str[0], "R\0", 1))
	{
		g_map->resolution_width = ft_strdup(str[1]);
		g_map->resolution_height = ft_strdup(str[2]);
	}
	else if (!ft_strncmp(str[0], "NO\0", 2))
		g_map->north_text = ft_strdup(str[1]);
	else if (!ft_strncmp(str[0], "SO\0", 2))
		g_map->south_text = ft_strdup(str[1]);
	else if (!ft_strncmp(str[0], "WE\0", 2))
		g_map->west_text = ft_strdup(str[1]);
	else if (!ft_strncmp(str[0], "EA\0", 2))
		g_map->east_text = ft_strdup(str[1]);
	else if (!ft_strncmp(str[0], "S\0", 2))
		g_map->sprite_text = ft_strdup(str[1]);
	else if (!ft_strncmp(str[0], "F\0", 1))
		g_map->floor_rgb = ft_strdup(str[1]);
	else if (!ft_strncmp(str[0], "C\0", 1))
		g_map->ceilling_rgb = ft_strdup(str[1]);
}

static	int		get_nb_of_lines(char *file)
{
	int		fd;
	int		out;
	int		nb_of_lines;
	char	*s;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (FALSE);
	out = 1;
	nb_of_lines = 0;
	while (out > 0)
	{
		out = get_next_line(fd, &s);
		if (s[0])
		{
			if (nb_of_lines < 8)
				print_test(s);
			nb_of_lines++;
		}
	}
	return (nb_of_lines);
}

static	int		read_map(int size, char *file)
{
	int		fd;
	int		out;
	int		nb_of_lines;
	char	*s;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (FALSE);
	g_map->map = malloc((size - 8 + 1) * sizeof(char *));
	out = 1;
	nb_of_lines = 0;
	while (out > 0)
	{
		out = get_next_line(fd, &s);
		if (s[0])
		{
			if (nb_of_lines >= 8)
				g_map->map[nb_of_lines - 8] = ft_strdup(s);
			nb_of_lines++;
		}
	}
	g_map->map[nb_of_lines - 8] = NULL;
	return (TRUE);
}

int read_map_file (char *file)
{
	int	bool_map;

	g_map = (t_map *)malloc(sizeof(t_map));
	bool_map = get_nb_of_lines(file);
	if (!bool_map)
		return (FALSE);
	bool_map = read_map(bool_map - 8, file);
	if (!bool_map)
		return (FALSE);
	return (TRUE);
}
