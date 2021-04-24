#include "../include/libft.h"

static	int	check_init_conditions(int fd, char ***line, char **t)
{
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
	{
		free(*t);
		return (-1);
	}
	return (1);
}

static	int	copy_array(char *t, char ***line, int out)
{
	if (out == 0)
		**line = ft_strdup(t);
	else if (out > 0)
		**line = ft_substr(t, 0, (ft_strchr(t, '\n') - t));
	return (out);
}

int	get_next_line(int fd, char **line)
{
	int				out;
	char			s[BUFFER_SIZE];
	char			*tmp;
	static char		*t;

	if (check_init_conditions(fd, &line, &t) == -1)
		return (-1);
	if (!t)
		t = ft_calloc(1, sizeof(char));
	out = read(fd, s, BUFFER_SIZE);
	while (!ft_strchr(t, '\n') && out > 0)
	{
		s[out] = '\0';
		tmp = ft_strjoin(t, s);
		ft_memdel((void **)&t);
		t = tmp;
		out = read(fd, s, BUFFER_SIZE);
	}
	if (copy_array(t, &line, out) == -1)
		return (-1);
	if (out > 0)
		tmp = ft_strdup(t + (ft_strlen(*line) + 1));
	else
		tmp = ft_strdup(t + (ft_strlen(*line)));
	ft_memdel((void **)&t);
	t = tmp;
	if (out == 0)
		return (0 * ft_memdel((void **)&t));
	else
		return (1);
}
