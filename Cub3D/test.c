#include "include/libft.h"

int main (int argc, char **argv)
{
	int		fd;
	int		out;
	int		i;
	char	**map;
	char	*s;

	if (argc != 2)
	{
		ft_printf("Error, error, error x_x\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	out = 1;
	i = 0;
	map = malloc((10) * sizeof(char *));
	while (out > 0)
	{
		out = get_next_line(fd, &s);
		if (s[0] != '\0')
			map[i++] = s;
	}
	map[i] = NULL;
	while(*map)
		ft_printf("%s\n", *map++);
	return (1);
}
